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
    if ((lpDirect3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
        return false;

    D3DPRESENT_PARAMETERS pp = {};
    pp.BackBufferWidth = width;
    pp.BackBufferHeight = height;
    pp.BackBufferFormat = D3DFMT_A8R8G8B8;
    pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    pp.Windowed = !fullScreen;
    pp.hDeviceWindow = hWnd;

    HRESULT hr;
    hr = lpDirect3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
        D3DCREATE_SOFTWARE_VERTEXPROCESSING, &pp, &lpDevice);

    if FAILED(hr)
        return false;

    return true;
}
bool Renderer::Release()
{
    SAFE_RELEASE(lpDevice);
    SAFE_RELEASE(lpDirect3D);

    return true;
}

void Renderer::Begin()
{
    if SUCCEEDED(lpDevice->BeginScene())
        lpDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(50, 50, 50), 1.0f, 0);
}
void Renderer::End()
{
    if SUCCEEDED(lpDevice->EndScene())
        lpDevice->Present(NULL, NULL, NULL, NULL);
}
