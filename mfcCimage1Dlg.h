
// mfcCimage1Dlg.h: 헤더 파일
//

#pragma once


// CmfcCimage1Dlg 대화 상자
class CmfcCimage1Dlg : public CDialogEx
{
// 생성입니다.
private:
	CImage m_image;
	BOOL validImgPos(int x, int y);
public:
	CmfcCimage1Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCCIMAGE1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnImage();
	afx_msg void OnBnClickedButtonLoad();
	afx_msg void OnBnClickedButtonSave();
	void UpdateDisplay();
	void MoveRect(int x, int y);
	void drawCircle(unsigned char* fm, int i, int j, int nRadius, int nGray);
	bool isInCircle(int i, int j, int nCenterX, int nCenterY, int nRadius);
	afx_msg void OnBnClickedButtonAction();
	int m_nRadius;
	int n_X1;
	afx_msg void OnBnClickedButtonDraw();
	int n_Y1;
	int m_saveCount = 0;
	int m_X2;
	int m_Y2;
	int nGray = 80;
};
