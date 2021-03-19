// VIRTUAL-KEY-CODES: https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes

#include <iostream>
#include <Windows.h>
#include <MMSystem.h>

using namespace std;

HHOOK hHook = NULL;

LRESULT CALLBACK MyHook(int nCode, WPARAM wParam, LPARAM lParam) {

    if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)
    {
        PKBDLLHOOKSTRUCT pKey = (PKBDLLHOOKSTRUCT)lParam;
        switch (pKey->vkCode)
        {
        case VK_SHIFT:
        case VK_LSHIFT:
        case VK_RSHIFT:
        case VK_CONTROL:
        case VK_MENU:
            return 0;
            break;
        case VK_CAPITAL:
            PlaySound(TEXT("./sounds/key-caps.wav"), NULL, SND_ASYNC);
            break;
        case VK_RETURN:
            PlaySound(TEXT("./sounds/key-confirm.wav"), NULL, SND_ASYNC);
            break;
        case VK_BACK:
            PlaySound(TEXT("./sounds/key-delete.wav"), NULL, SND_ASYNC);
            break;
        case VK_LEFT:
        case VK_UP:
        case VK_RIGHT:
        case VK_DOWN:
            PlaySound(TEXT("./sounds/key-movement.wav"), NULL, SND_ASYNC);
            break;
        default:
            switch (rand() % 4)
            {
            case 0:
                PlaySound(TEXT("./sounds/key-press-1.wav"), NULL, SND_ASYNC);
                break;
            case 1:
                PlaySound(TEXT("./sounds/key-press-2.wav"), NULL, SND_ASYNC);
                break;
            case 2:
                PlaySound(TEXT("./sounds/key-press-3.wav"), NULL, SND_ASYNC);
                break;
            case 3:
                PlaySound(TEXT("./sounds/key-press-4.wav"), NULL, SND_ASYNC);
                break;
            };
        };
    } return CallNextHookEx(hHook, nCode, wParam, lParam);
}

int main()
{
    hHook = SetWindowsHookEx(WH_KEYBOARD_LL, MyHook, NULL, NULL);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {

    };
}