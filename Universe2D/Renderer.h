#pragma once
class Renderer
{
private:
    LPDIRECT3D9 lpDirect3D;
    LPDIRECT3DDEVICE9 lpDevice;
    
    LPD3DXSPRITE lpSprite;

public:
    Renderer();
    ~Renderer();

    bool Initialize(int width, int height, bool fullScreen);
    bool Release();

    void Begin();
    void End();

public:
    LPDIRECT3D9 GetDirect3D() const { return lpDirect3D; }
    LPDIRECT3DDEVICE9 GetDevice() const { return lpDevice; }

    LPD3DXSPRITE GetSprite() const { return lpSprite; }
};

