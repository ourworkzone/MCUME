#ifndef EMUAPI_H
#define EMUAPI_H

#include "platform_config.h"

#define CUSTOM_SND  1
//#define TIMER_REND  1

#define EXTRA_HEAP  0x10

// Title:     <                        >
#define TITLE "      UAE Emulator      "
#define ROMSDIR "/amiga"

#define emu_Init(ROM1,ROM2) {uae_Start(ROM1,ROM2);}
#define emu_Init2() {uae_Init();}
#define emu_Step(x) {uae_Step();}
#define emu_Input(x) {uae_Input(x);}

#define PALETTE_SIZE         1
#define VID_FRAME_SKIP       0x0
#define TFT_VBUFFER_YCROP    0
#define SINGLELINE_RENDERING 1

#define R32(rgb) ((rgb>>16)&0xff) 
#define G32(rgb) ((rgb>>8)&0xff) 
#define B32(rgb) (rgb & 0xff) 

#define ACTION_NONE          0
#define ACTION_MAXKBDVAL     16
#define ACTION_EXITKBD       128
#define ACTION_RUN1          129
#define ACTION_RUN2          130
#define ACTION_RUN3          131


#ifdef KEYMAP_PRESENT
#ifdef TEECOMPUTER

/*
  AK_1,AK_2,AK_3,AK_4,AK_5,AK_6,AK_7,AK_8,AK_9,AK_0, //0 (1-10)
  AK_Q,AK_W,AK_E,AK_R,AK_T,AK_Y,AK_U,AK_I,AK_O,AK_P, //1 (11-20)
  AK_A,AK_S,AK_D,AK_F,AK_G,AK_H,AK_J,AK_K,AK_L,AK_ENT, //2 (21-30)
  AK_Z,AK_X,AK_C,AK_V,AK_B,AK_N,AK_M,AK_COMMA,AK_BS,AK_SPC, //3 (31-40)
  AK_F1,AK_F2,AK_F3,AK_F4,AK_F5,AK_F6,AK_F7,AK_F8,AK_F9,AK_F10, //4 (41-50)
  AK_NPMUL,AK_NPSUB,AK_NPADD,AK_NPDIV,AK_NPDEL,AK_QUOTE,AK_BACKQUOTE,AK_SEMICOLON,AK_BACKSLASH,AK_PERIOD, //5 (51-60)
  AK_NPLPAREN,AK_NPRPAREN,AK_LBRACKET,AK_RBRACKET,AK_EQUAL,AK_UP,AK_DN,AK_LF,AK_RT //6  (61-69)
*/

const unsigned short key_map1[] = {
  11,12,13,14,15,16,17,18,19,20, 39,
  0, 21,22,23,24,25,26,27,28,29,30,
  0, 31,32,33,34,35,36,37,60,40,
  66,68,69,67 //U L R D
  };
  
const unsigned short key_map2[] = {
  1, 2, 3, 4, 5, 6, 7, 8, 9, 10,0,
  0, 0,0,0,0,0,53,0,51,52,54,
  0, 61,62,0,59,0,0,0,38,58,
  66,68,69,67
  };

const unsigned short key_map3[] = {
  40,41,42,43,44,45,46,47,48,49, 0, // function keys
  0, 0,0,0,0,0,0,0,0,0,0,
  0, 63,64,0,0,0,0,0,58,65,
  66,68,69,67
  };

const unsigned short matkeys[] = {
  0x020,0x120,0x220,0x320,0x420,0x408,0x308,0x208,0x108,0x008,0x002, // row 1
  0x510,0x010,0x110,0x210,0x310,0x410,0x401,0x301,0x201,0x101,0x001, // row 2
  0x520,0x102,0x202,0x302,0x402,0x404,0x304,0x204,0x104,0x004, // row 3
  0x508,0x501,0x502,0x504 }; // cursor keys

   
#endif
#endif


#define MASK_JOY2_RIGHT 0x0001
#define MASK_JOY2_LEFT  0x0002
#define MASK_JOY2_UP    0x0004
#define MASK_JOY2_DOWN  0x0008
#define MASK_JOY2_BTN   0x0010
#define MASK_KEY_USER1  0x0020
#define MASK_KEY_USER2  0x0040
#define MASK_KEY_USER3  0x0080
#define MASK_JOY1_RIGHT 0x0100
#define MASK_JOY1_LEFT  0x0200
#define MASK_JOY1_UP    0x0400
#define MASK_JOY1_DOWN  0x0800
#define MASK_JOY1_BTN   0x1000
#define MASK_KEY_USER4  0x2000



#ifdef __cplusplus  
extern "C" {
#endif
extern void emu_init(void);
extern void emu_start(void);
extern void emu_printf(char * text);
extern void emu_printi(int val);
extern void emu_printh(int val);
extern void * emu_Malloc(int size);
extern void * emu_MallocI(int size);
extern void emu_Free(void * pt);

 
extern int emu_FileOpen(char * filename);
extern int emu_FileRead(char * buf, int size);
extern unsigned char emu_FileGetc(void);
extern int emu_FileTell(void);
extern int emu_FileSeek(int seek);
extern void emu_FileClose(void);
extern int emu_FileSize(char * filename);
extern int emu_LoadFile(char * filename, char * buf, int size);
extern int emu_LoadFileSeek(char * filename, char * buf, int size, int seek);
extern void emu_FileTempInit(void); 
extern void emu_FileTempRead(int addr, unsigned char * val, int n); 
extern void emu_FileTempWrite(int addr, unsigned char val); 


extern void emu_SetPaletteEntry(unsigned char r, unsigned char g, unsigned char b, int index);
extern void emu_DrawScreen(unsigned char * VBuf, int width, int height, int stride);
extern void emu_DrawLine(unsigned char * VBuf, int width, int height, int line);
extern void emu_DrawLine16(unsigned short * VBuf, int width, int height, int line);
extern void emu_DrawLine8(unsigned char * VBuf, int width, int height, int line);
extern void emu_CopyLine(int width, int height, int ysrc, int ydst);
extern void emu_DrawVsync(void);
extern int emu_FrameSkip(void);
extern void * emu_LineBuffer(int line);
extern void emu_tweakVideo(int shiftdelta, int numdelta, int denomdelta);

extern bool menuActive(void);
extern char * menuSelection(void);
extern void toggleMenu(bool on);
extern int  handleMenu(unsigned short bClick);

extern void emu_InitJoysticks(void);
extern int emu_SwapJoysticks(int statusOnly);
extern unsigned short emu_DebounceLocalKeys(void);
extern int emu_ReadKeys(void);
extern int emu_GetPad(void);
extern int emu_GetMouse(int *x, int *y, int *buts);
extern int emu_MouseDetected(void);
extern int emu_KeyboardDetected(void);
extern int emu_ReadAnalogJoyX(int min, int max);
extern int emu_ReadAnalogJoyY(int min, int max);
extern int emu_ReadI2CKeyboard(void);
extern void emu_KeyboardOnUp(int keymodifer, int key);
extern void emu_KeyboardOnDown(int keymodifer, int key);

extern void emu_sndPlaySound(int chan, int volume, int freq);
extern void emu_sndPlayBuzz(int size, int val);
extern void emu_sndInit();
extern void emu_resetus(void);
extern int emu_us(void);

extern int emu_setKeymap(int index);

#ifdef __cplusplus
}
#endif

#endif
