#include "sevid000.h"

void S_2877_Chain4ByteWrite_00000002_00000008 (IU32 eaOff, IU8 eaVal)
{
  C4BWRTF1(2877, UCB4MSK, TRANS1);
}

void S_2878_Chain4ByteWrite_00000002_00000009 (IU32 eaOff, IU8 eaVal)
{
  C4BWRTF(2878, UCB4MSK, TRANS1);
}

void S_2879_Chain4ByteWrite_00000002_0000000e (IU32 eaOff, IU8 eaVal)
{
  C4BWRTF1(2879, UCBMSK, TRANS1);
}

void S_2880_Chain4ByteWrite_00000002_0000000f (IU32 eaOff, IU8 eaVal)
{
  C4BWRTF(2880, UCBMSK, TRANS1);
}

void S_2881_Chain4ByteFill_00000002_00000008 (IU32 eaOff, IU8 eaVal, IU32 count)
{
  C4BFLL(2881, UCB4MSK, TRANS1);
}

void S_2882_Chain4ByteFill_00000002_00000009 (IU32 eaOff, IU8 eaVal, IU32 count)
{
  C4BFLL1(2882, UCB4MSK, TRANS1);
}

void S_2883_Chain4ByteFill_00000002_0000000e (IU32 eaOff, IU8 eaVal, IU32 count)
{
  C4BFLL(2883, UCBMSK, TRANS1);
}

void S_2884_Chain4ByteFill_00000002_0000000f (IU32 eaOff, IU8 eaVal, IU32 count)
{
  C4BFLL1(2884, UCBMSK, TRANS1);
}

void S_2885_Chain4ByteMove_00000002_00000008_00000000 (IU32 eaOff, IHPE fromOff, IU32 count, IBOOL srcInRAM)
{
  C4BMOVFW(2885, S_2886_CopyBytePlnByPlnChain4_00000002_00000008_00000000_00000000);
}

void S_2886_CopyBytePlnByPlnChain4_00000002_00000008_00000000_00000000 (IU32 eaOff, IHPE fromOff, IHPE destOff, IU32 count, IBOOL srcInRAM)
{
  C4BCPYB4PLN1(2886,+1,TRANS1,UCB4MSKL);
}

void S_2887_Chain4ByteMove_00000002_00000009_00000000 (IU32 eaOff, IHPE fromOff, IU32 count, IBOOL srcInRAM)
{
  C4BMOVFW(2887, S_2888_CopyByte4PlaneChain4_00000002_00000009_00000000_00000000);
}

void S_2888_CopyByte4PlaneChain4_00000002_00000009_00000000_00000000 (IU32 eaOff, IHPE fromOff, IHPE destOff, IU32 count, IBOOL srcInRAM)
{
  C4BCPYB4PLN(2888,+1,TRANS1,UCB4MSKL);
}

void S_2889_Chain4ByteMove_00000002_0000000e_00000000 (IU32 eaOff, IHPE fromOff, IU32 count, IBOOL srcInRAM)
{
  C4BMOVFW(2889, S_2890_CopyBytePlnByPlnChain4_00000002_0000000e_00000000_00000000);
}

void S_2890_CopyBytePlnByPlnChain4_00000002_0000000e_00000000_00000000 (IU32 eaOff, IHPE fromOff, IHPE destOff, IU32 count, IBOOL srcInRAM)
{
  C4BCPYB4PLN1(2890,+1,TRANS1,UCBMSKL);
}

void S_2891_Chain4ByteMove_00000002_0000000f_00000000 (IU32 eaOff, IHPE fromOff, IU32 count, IBOOL srcInRAM)
{
  C4BMOVFW(2891, S_2892_CopyByte4PlaneChain4_00000002_0000000f_00000000_00000000);
}

void S_2892_CopyByte4PlaneChain4_00000002_0000000f_00000000_00000000 (IU32 eaOff, IHPE fromOff, IHPE destOff, IU32 count, IBOOL srcInRAM)
{
  C4BCPYB4PLN(2890,+1,TRANS1,UCBMSKL);
}
