#include "Precompiled.h"
#include "Renderer.h"

Renderer::Renderer()
{
}
Renderer::~Renderer()
{
    Release();
}

bool Renderer::Initialize(HWND hWnd, int width, int height, bool fullScreen)
{
    if ((m_lpDirect3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
        return false;

    D3DPRESENT_PARAMETERS pp = {};
    pp.BackBufferWidth = width;
    pp.BackBufferHeight = height;
    pp.BackBufferFormat = D3DFMT_A8R8G8B8;
    pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    pp.Windowed = !fullScreen;
    pp.hDeviceWindow = hWnd;

    HRESULT hr;

    hr = m_lpDirect3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
        D3DCREATE_SOFTWARE_VERTEXPROCESSING, &pp, &m_lpDevice);

	if FAILED(hr) {
		return false;
	}

    m_lpDevice->SetRenderState(D3DRS_MULTISAMPLEANTIALIAS, TRUE);
	m_lpDevice->SetRenderState(D3DRS_ANTIALIASEDLINEENABLE, TRUE);

	if FAILED(D3DXCreateSprite(m_lpDevice, &m_lpSprite)) {
		return false;
	}

    return true;
}
bool Renderer::Release()
{
	SAFE_RELEASE(m_lpSprite);
    SAFE_RELEASE(m_lpDevice);
    SAFE_RELEASE(m_lpDirect3D);

    return true;
}

void Renderer::Begin()
{
    if SUCCEEDED(m_lpDevice->BeginScene())
		m_lpDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(50, 50, 50), 1.0f, 0);
}
void Renderer::End()
{
    if SUCCEEDED(m_lpDevice->EndScene())
		m_lpDevice->Present(NULL, NULL, NULL, NULL);
}
