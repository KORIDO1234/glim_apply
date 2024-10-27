
// mfcCimage1Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "mfcCimage1.h"
#include "mfcCimage1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CmfcCimage1Dlg 대화 상자



CmfcCimage1Dlg::CmfcCimage1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCCIMAGE1_DIALOG, pParent)
	, n_X1(0)
	, n_Y1(0)
	, m_X2(0)
	, m_Y2(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmfcCimage1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_X1, n_X1);
	DDX_Text(pDX, IDC_EDIT_Y1, n_Y1);
	DDX_Text(pDX, IDC_EDIT_X2, m_X2);
	DDV_MinMaxInt(pDX, m_X2, 30, 970);
	DDX_Text(pDX, IDC_EDIT_Y2, m_Y2);
	DDV_MinMaxInt(pDX, m_Y2, 30, 450);
}

BEGIN_MESSAGE_MAP(CmfcCimage1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_IMAGE, &CmfcCimage1Dlg::OnBnClickedBtnImage)
	ON_BN_CLICKED(IDC_BUTTON_Load, &CmfcCimage1Dlg::OnBnClickedButtonLoad)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CmfcCimage1Dlg::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_ACTION, &CmfcCimage1Dlg::OnBnClickedButtonAction)
	ON_BN_CLICKED(IDC_BUTTON_DRAW, &CmfcCimage1Dlg::OnBnClickedButtonDraw)
END_MESSAGE_MAP()


// CmfcCimage1Dlg 메시지 처리기

BOOL CmfcCimage1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CmfcCimage1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CmfcCimage1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CmfcCimage1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CmfcCimage1Dlg::OnBnClickedBtnImage()
{
	int nWidth = 1000;
	int nHeight = 480;
	int nBpp = 8;
	int nGray = 80;
	int nRadius = rand() % 21 + 10;
	m_image.Create(nWidth, -nHeight, nBpp);
	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++) {
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
			m_image.SetColorTable(0, 256, rgb);
		}
	}
	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	memset(fm, 0x00, sizeof(unsigned char) * nWidth * nHeight);
	//drawCircle(fm, nSttX, nSttY, nRadius, nGray);

	/*for (int j = 0; j < nHeight; j++) {
		for (int i = 0; i < nWidth; i++) {
			fm[j * nPitch + i] = j*10 % 255;
		}
	}
	fm[16 * nPitch + 12] = 0;*/
	UpdateDisplay();

	
}




//CString g_strFileImage = _T("c:\\image\\save.bmp");
void CmfcCimage1Dlg::OnBnClickedButtonLoad()
{
	CFileDialog fileDlg(TRUE, _T("bmp"), NULL, OFN_FILEMUSTEXIST, _T("Bitmap Files (*.bmp)|*.bmp|All Files (*.*)|*.*||"));

	if (fileDlg.DoModal() == IDOK)
	{
		CString g_strFileImage = fileDlg.GetPathName();

		if (m_image != NULL) {
			m_image.Destroy();
		}
		Invalidate(); 
		UpdateWindow();
		m_image.Load(g_strFileImage);

		UpdateDisplay();
	}
	unsigned char* fm = (unsigned char*)m_image.GetBits();
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nPitch = m_image.GetPitch();
	CRect rect(0, 0, nWidth, nHeight);
	int sumX = 0;
	int sumY = 0;
	int count = 0;
	for (int j = rect.top; j < rect.bottom; j++) {
		for (int i = rect.left; i < rect.right; i++) {
			if (fm[j * nPitch + i] == nGray) {
				sumX += i;
				sumY += j;
				count++;
			}
		}
	}
	double dCenterX = (double)sumX / count;
	double dCenterY = (double)sumY / count;

	CDC* pDC = GetDC();
	int xSize = 5;
	pDC->MoveTo(dCenterX - xSize, dCenterY - xSize);
	pDC->LineTo(dCenterX + xSize, dCenterY + xSize);
	pDC->MoveTo(dCenterX + xSize, dCenterY - xSize);
	pDC->LineTo(dCenterX - xSize, dCenterY + xSize);

	// 좌표 출력
	CString strCoordinates;
	strCoordinates.Format(_T("Center: (%.1f, %.1f)"), dCenterX, dCenterY);
	pDC->TextOut(dCenterX + 25, dCenterY - 10, strCoordinates); // 좌표 출력
	ReleaseDC(pDC); // 디바이스 컨텍스트 해제
}



void CmfcCimage1Dlg::OnBnClickedButtonSave()
{
	m_image.Save(_T("c:\\image\\save.bmp"));
}

void CmfcCimage1Dlg::UpdateDisplay()
{
	CClientDC dc(this);
	m_image.Draw(dc, 0, 0);
}

void CmfcCimage1Dlg:: MoveRect(int stepX, int stepY)
{
	static int nSttX1 = GetDlgItemInt(IDC_EDIT_X1);
	static int nSttY1 = GetDlgItemInt(IDC_EDIT_Y1);
	int nSttX2 = GetDlgItemInt(IDC_EDIT_X2);
	int nSttY2 = GetDlgItemInt(IDC_EDIT_Y2);
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nPitch = m_image.GetPitch();
	//int stepX = (nSttX2 - nSttX1) / 300;
	//int stepY = (nSttY2 - nSttY1) / 300;

	unsigned char* fm = (unsigned char*)m_image.GetBits();
	memset(fm, 0x00, nWidth * nHeight);
	drawCircle(fm, nSttX1, nSttY1, m_nRadius, nGray);
	
	nSttX1 += stepX;
	nSttY1 += stepY;
	if ((stepX > 0 && nSttX1 >= nSttX2) || (stepX < 0 && nSttX1 <= nSttX2)) {
		nSttX1 = nSttX2; 
	}

	if ((stepY > 0 && nSttY1 >= nSttY2) || (stepY < 0 && nSttY1 <= nSttY2)) {
		nSttY1 = nSttY2;
	}
	UpdateDisplay();
}

void CmfcCimage1Dlg::OnBnClickedButtonAction()
{
	int nSttX1 = GetDlgItemInt(IDC_EDIT_X1);
	int nSttY1 = GetDlgItemInt(IDC_EDIT_Y1);
	int nSttX2 = GetDlgItemInt(IDC_EDIT_X2);
	int nSttY2 = GetDlgItemInt(IDC_EDIT_Y2);
	int stepX = max(1, abs(nSttX2 - nSttX1) / 300) * ((nSttX2 > nSttX1) ? 1 : -1);
	int stepY = max(1, abs(nSttY2 - nSttY1) / 300) * ((nSttY2 > nSttY1) ? 1 : -1);
	for (int i = 0; i < 100; i++) {
		MoveRect(stepX, stepY);
		Sleep(3);
	}
	CString filepath;
	filepath.Format(_T("c:\\image\\save%d.bmp"), ++m_saveCount);
	m_image.Save(filepath);
}

BOOL CmfcCimage1Dlg::validImgPos(int x, int y)
{
	//BOOL bRet = false;
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	CRect rect(0, 0, nWidth, nHeight);
	return rect.PtInRect(CPoint(x, y));

	//if (x > 0 && x <= nWidth && y > 0 && y <= nHeight) {
	//	bRet = true;
	//}
	//return bRet;
}

void CmfcCimage1Dlg::drawCircle(unsigned char* fm, int x, int y, int nRadius, int nGray)
{
	int nCenterX = x;
	int nCenterY = y;
	int nPitch = m_image.GetPitch();

	for (int j = y -nRadius; j < y + nRadius; j++) {
		for (int i = x -nRadius; i < x + nRadius; i++) {
			if (isInCircle(i, j, nCenterX, nCenterY, nRadius)) {
				fm[j * nPitch + i] = nGray;
			}
		}
	}
}

bool CmfcCimage1Dlg::isInCircle(int i, int j, int nCenterX, int nCenterY, int nRadius)
{
	
	bool bRet = false;

	double dX = i - nCenterX;
	double dY = j - nCenterY;
	double dDist = dX * dX + dY * dY;
	if (dDist < nRadius * nRadius) {
		bRet = true;
	}

	return bRet;
}


void CmfcCimage1Dlg::OnBnClickedButtonDraw()
{
	int nSttX = GetDlgItemInt(IDC_EDIT_X1);
	int nSttY = GetDlgItemInt(IDC_EDIT_Y1);
	int nSttX2 = GetDlgItemInt(IDC_EDIT_X2);
	int nSttY2 = GetDlgItemInt(IDC_EDIT_Y2);

	if (nSttX < 30 || nSttX > 970 || nSttY < 30 || nSttY > 450 || nSttX2 < 30 || nSttX2 > 970 || nSttY2 < 30 || nSttY2 > 450) {
		MessageBox(_T("X값은 30~970, Y값은 30~450 사이로 입력해주세요."), _T("원 생성 불가"), MB_OK | MB_ICONERROR);
		return;
	}

	int nWidth = 1000;
	int nHeight = 480;
	int nBpp = 8;
	m_nRadius = rand() % 21 + 10;

	m_image.Destroy();
	m_image.Create(nWidth, -nHeight, nBpp);
	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++) {
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
			m_image.SetColorTable(0, 256, rgb);
		}
	}
	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	memset(fm, 0x00, sizeof(unsigned char) * nWidth * nHeight);
	drawCircle(fm, nSttX, nSttY, m_nRadius, nGray);
	UpdateDisplay();
}
