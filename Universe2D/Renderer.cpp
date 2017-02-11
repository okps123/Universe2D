#include "Precompiled.h"
#include "Renderer.h"

Renderer::Renderer()
{
}
Renderer::~Renderer()
{
    Release();
}

bool Renderer::Initialize(int width, int height, bool fullScreen)
{
    if ((lpDirect3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
        return false;

    D3DPRESENT_PARAMETERS pp = {};
    pp.BackBufferFormat = D3DFMT_UNKNOWN;
    pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    pp.Windowed = !fullScreen;

    HRESULT hr;
    hr = lpDirect3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, NULL,
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
    lpDevice->BeginScene();
    lpDevice->Clear(0, NULL, NULL, D3DCOLOR_XRGB(100, 100, 100), 1.0f, 0);
}
void Renderer::End()
{
    lpDevice->EndScene();
    lpDevice->Present(NULL, NULL, NULL, NULL);
}
