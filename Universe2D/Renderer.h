#pragma once
class Renderer 
{
private:
    LPDIRECT3D9 m_lpDirect3D;
    LPDIRECT3DDEVICE9 m_lpDevice;
    
    LPD3DXSPRITE m_lpSprite;

public:
    Renderer();
    ~Renderer();

    bool Initialize(HWND hWnd, int width, int height, bool fullScreen);
    bool Release();

    void Begin();
    void End();

public:
    LPDIRECT3D9 GetDirect3D() const { return m_lpDirect3D; }
    LPDIRECT3DDEVICE9 GetDevice() const { return m_lpDevice; }

    LPD3DXSPRITE GetSprite() const { return m_lpSprite; }
};

