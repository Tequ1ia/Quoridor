
// QuoridorDlg.h: 头文件
//

#pragma once

#include "GameDisplay.h"
#include "GameData.h"
#include "AI.h"
#include <vector>
using namespace std;

// CQuoridorDlg 对话框
class CQuoridorDlg : public CDialogEx
{
// 构造
public:
	CQuoridorDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QUORIDOR_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	HICON m_hIcon;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	static DWORD WINAPI QuoridorGame(LPVOID pParameter);

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButtonRegame();
	afx_msg void OnBnClickedButtonUndo();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

	void updateInformationText();
	
public:
	CComboBox m_whofirst;
	HANDLE mGameHandle;

	bool isGameOver = false;
	bool isGameStart = false;
	volatile bool isHandleWaittingOperate = false;
	volatile bool isHandleWaittingPaint = false;

	Order mOrder;
	int mTurn;
	
	GameData mGameData;
	GameDisplay mGameDisplay;
	CString mText = '\0';
	AI * mAI[PLAYER_NUM];
	int IDC_STATIC_WALLNUM[PLAYER_NUM] = { IDC_STATIC_WALLNUM_PLAYER1, IDC_STATIC_WALLNUM_PLAYER2 };
	int IDC_STATIC_SHORTPATH[PLAYER_NUM] = { IDC_STATIC_SHORTPATH_PLAYER1, IDC_STATIC_SHORTPATH_PLAYER2 };
	COLORREF mColor[PLAYER_NUM] = { COLOR_BLACK, COLOR_RED };
	
	afx_msg void OnClose();
};
