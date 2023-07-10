#pragma once
#include <cstdint>

extern MemoryUtility               MemUtil;
extern DWORD                       PROCESS_PID;
extern QWORD                       PROCESS_PEB;
extern VMMDLL_PROCESS_INFORMATION  PROCESS_INFO;
extern QWORD                       MODULE_BASE_ADDRESS;

template <class uintptr_t>

uintptr_t Read(QWORD address) {
    QWORD buff;

    MemUtil.readMemory(PROCESS_PID, address, &buff);

    return buff;
}

namespace offsets {
    auto ref_def_ptr = 0x12ACC430;
    auto name_array = 0x12AEAAA0;
    auto name_array_pos = 0x5E70;
    auto loot_ptr = 0xCA372BC;
    auto camera_base = 0x131892E0;
    auto camera_pos = 0x1F8;
    auto local_index = 0xD30D0;
    auto local_index_pos = 0x2E4;
    auto game_mode = 0xFF1FDB0;
    auto weapon_definitions = 0x12A35310;
    auto distribute = 0xBAA2A88;
    auto visible_offset = 0xA80;
    auto visible = 0x2699100;
    namespace player {
        auto size = 0x6280;
        auto valid = 0x1533;
        auto pos = 0x1248;
        auto team = 0x190;
        auto weapon_index = 0x7C4;
        auto dead_1 = 0x5F8C;
        auto dead_2 = 0x154D;
    }
    namespace bone {
        auto bone_base = 0xA1E10;
        auto size = 0x188;
        auto offset = 0xD8;
    }
}

uintptr_t get_client_info(QWORD BaseAddress, QWORD Peb)
{
    auto mb = BaseAddress;
    uint64_t rax = mb, rbx = mb, rcx = mb, rdx = mb, rdi = mb, rsi = mb, r8 = mb, r9 = mb, r10 = mb, r11 = mb, r12 = mb, r13 = mb, r14 = mb, r15 = mb;
    rbx = Read<uintptr_t>(mb + 0x12ACBFD8);
    if (!rbx)
        return rbx;
    rcx = ~Peb;              //mov rcx, gs:[rax]
    rax = mb + 0x7A98;              //lea rax, [0xFFFFFFFFFDD825A5]
    rcx -= rax;             //sub rcx, rax
    rbx += rcx;             //add rbx, rcx
    rax = rbx;              //mov rax, rbx
    rax >>= 0x3;            //shr rax, 0x03
    rbx ^= rax;             //xor rbx, rax
    rax = rbx;              //mov rax, rbx
    rax >>= 0x6;            //shr rax, 0x06
    rbx ^= rax;             //xor rbx, rax
    rax = rbx;              //mov rax, rbx
    rax >>= 0xC;            //shr rax, 0x0C
    rbx ^= rax;             //xor rbx, rax
    rax = rbx;              //mov rax, rbx
    rax >>= 0x18;           //shr rax, 0x18
    rbx ^= rax;             //xor rbx, rax
    rax = 0x87EB48CBA4287557;               //mov rax, 0x87EB48CBA4287557
    rcx = rbx;              //mov rcx, rbx
    rcx >>= 0x30;           //shr rcx, 0x30
    rcx ^= rbx;             //xor rcx, rbx
    rcx *= rax;             //imul rcx, rax
    rax = 0xD579FA0DAE99EEE;                //mov rax, 0xD579FA0DAE99EEE
    rcx += rax;             //add rcx, rax
    rax = rcx;              //mov rax, rcx
    rax >>= 0xF;            //shr rax, 0x0F
    rcx ^= rax;             //xor rcx, rax
    rax = rcx;              //mov rax, rcx
    rax >>= 0x1E;           //shr rax, 0x1E
    rcx ^= rax;             //xor rcx, rax
    rbx = rcx;              //mov rbx, rcx
    rax = 0;                //and rax, 0xFFFFFFFFC0000000
    rbx >>= 0x3C;           //shr rbx, 0x3C
    rax = _rotl64(rax, 0x10);               //rol rax, 0x10
    rbx ^= rcx;             //xor rbx, rcx
    rax ^= Read<uintptr_t>(mb + 0xA4CA0DD);           //xor rax, [0x0000000008244B57]
    rax = _byteswap_uint64(rax);            //bswap rax
    rbx *= Read<uintptr_t>(rax + 0x7);                //imul rbx, [rax+0x07]
    return rbx;
}
uint64_t get_client_info_base(QWORD BaseAddress, QWORD Peb)
{
    auto mb = BaseAddress;
    uint64_t rax = mb, rbx = mb, rcx = mb, rdx = mb, rdi = mb, rsi = mb, r8 = mb, r9 = mb, r10 = mb, r11 = mb, r12 = mb, r13 = mb, r14 = mb, r15 = mb;
    r8 = Read<uintptr_t>(get_client_info(BaseAddress, Peb) + 0x160980);
    if (!r8)
        return r8;
    rbx = ~Peb;              //mov rbx, gs:[rax]
    rax = rbx;              //mov rax, rbx
    rax = _rotr64(rax, 0xD);                //ror rax, 0x0D
    rax &= 0xF;
    switch (rax) {
    case 0:
    {
        r10 = Read<uintptr_t>(mb + 0xA4CA102);            //mov r10, [0x0000000002F0EA2F]
        rax = r8;               //mov rax, r8
        rax >>= 0x16;           //shr rax, 0x16
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x2C;           //shr rax, 0x2C
        r8 ^= rax;              //xor r8, rax
        r8 -= rbx;              //sub r8, rbx
        rax = 0xC35A4D5374479F2;                //mov rax, 0xC35A4D5374479F2
        r8 += rax;              //add r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x20;           //shr rax, 0x20
        rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
        r8 ^= rax;              //xor r8, rax
        rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
        rcx ^= r10;             //xor rcx, r10
        rcx = _byteswap_uint64(rcx);            //bswap rcx
        r8 *= Read<uintptr_t>(rcx + 0x9);                 //imul r8, [rcx+0x09]
        rax = r8;               //mov rax, r8
        rax >>= 0x4;            //shr rax, 0x04
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x8;            //shr rax, 0x08
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x10;           //shr rax, 0x10
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x20;           //shr rax, 0x20
        r8 ^= rax;              //xor r8, rax
        rax = 0x24EA08DF117330C7;               //mov rax, 0x24EA08DF117330C7
        r8 ^= rax;              //xor r8, rax
        rax = 0x2D90FA064AD9F971;               //mov rax, 0x2D90FA064AD9F971
        r8 *= rax;              //imul r8, rax
        return r8;
    }
    case 1:
    {
        r11 = mb;               //lea r11, [0xFFFFFFFFF8A4446B]
        r10 = Read<uintptr_t>(mb + 0xA4CA102);            //mov r10, [0x0000000002F0E517]
        rax = r8;               //mov rax, r8
        rax >>= 0x15;           //shr rax, 0x15
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x2A;           //shr rax, 0x2A
        r8 ^= rax;              //xor r8, rax
        rax = 0x2DBBDA8DE6FFC239;               //mov rax, 0x2DBBDA8DE6FFC239
        r8 *= rax;              //imul r8, rax
        r8 -= r11;              //sub r8, r11
        rax = 0x569D26880A4322EB;               //mov rax, 0x569D26880A4322EB
        r8 *= rax;              //imul r8, rax
        rax = mb + 0x52C7;              //lea rax, [0xFFFFFFFFF8A49373]
        rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
        rax = ~rax;             //not rax
        rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
        rax ^= rbx;             //xor rax, rbx
        rcx ^= r10;             //xor rcx, r10
        r8 += rax;              //add r8, rax
        rcx = _byteswap_uint64(rcx);            //bswap rcx
        r8 *= Read<uintptr_t>(rcx + 0x9);                 //imul r8, [rcx+0x09]
        r8 += r11;              //add r8, r11
        rax = 0x52640EFEA7727BD5;               //mov rax, 0x52640EFEA7727BD5
        r8 -= rax;              //sub r8, rax
        return r8;
    }
    case 2:
    {
        r11 = mb;               //lea r11, [0xFFFFFFFFF8A44032]
        rcx = mb + 0x5A2CDFA5;          //lea rcx, [0x0000000052D11FCB]
        r10 = Read<uintptr_t>(mb + 0xA4CA102);            //mov r10, [0x0000000002F0E0F2]
        rax = 0;                //and rax, 0xFFFFFFFFC0000000
        rax = _rotl64(rax, 0x10);               //rol rax, 0x10
        rax ^= r10;             //xor rax, r10
        rax = _byteswap_uint64(rax);            //bswap rax
        r8 *= Read<uintptr_t>(rax + 0x9);                 //imul r8, [rax+0x09]
        rax = r8;               //mov rax, r8
        rax >>= 0xB;            //shr rax, 0x0B
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x16;           //shr rax, 0x16
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x2C;           //shr rax, 0x2C
        r8 ^= rax;              //xor r8, rax
        rax = r11 + 0xe31b;             //lea rax, [r11+0xE31B]
        rax += rbx;             //add rax, rbx
        r8 += rax;              //add r8, rax
        rax = rbx;              //mov rax, rbx
        uintptr_t RSP_0x70;
        RSP_0x70 = mb + 0x5DF61987;             //lea rax, [0x00000000569A5983] : RSP+0x70
        rax ^= RSP_0x70;                //xor rax, [rsp+0x70]
        r8 -= rax;              //sub r8, rax
        rax = rbx;              //mov rax, rbx
        rax = ~rax;             //not rax
        rax ^= rcx;             //xor rax, rcx
        r8 -= rax;              //sub r8, rax
        rax = 0xFA7D43A4072DDDF3;               //mov rax, 0xFA7D43A4072DDDF3
        r8 ^= rax;              //xor r8, rax
        rax = 0x1BEF6CDBCB4BF6E1;               //mov rax, 0x1BEF6CDBCB4BF6E1
        r8 *= rax;              //imul r8, rax
        rax = 0x706FFD36014803E0;               //mov rax, 0x706FFD36014803E0
        r8 ^= rax;              //xor r8, rax
        return r8;
    }
    case 3:
    {
        r11 = mb;               //lea r11, [0xFFFFFFFFF8A43C47]
        r10 = mb + 0x75EAD525;          //lea r10, [0x000000006E8F115B]
        r9 = Read<uintptr_t>(mb + 0xA4CA102);             //mov r9, [0x0000000002F0DCFB]
        rax = r8;               //mov rax, r8
        rax >>= 0x12;           //shr rax, 0x12
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x24;           //shr rax, 0x24
        r8 ^= rax;              //xor r8, rax
        uintptr_t RSP_0x48;
        RSP_0x48 = 0xD891FBA7C28BF266;          //mov rax, 0xD891FBA7C28BF266 : RSP+0x48
        r8 ^= RSP_0x48;                 //xor r8, [rsp+0x48]
        rax = rbx;              //mov rax, rbx
        rax ^= r10;             //xor rax, r10
        r8 -= rax;              //sub r8, rax
        rax = 0x7306CD487DB9D041;               //mov rax, 0x7306CD487DB9D041
        r8 ^= rax;              //xor r8, rax
        r8 += rbx;              //add r8, rbx
        rax = 0;                //and rax, 0xFFFFFFFFC0000000
        rax = _rotl64(rax, 0x10);               //rol rax, 0x10
        rax ^= r9;              //xor rax, r9
        rax = _byteswap_uint64(rax);            //bswap rax
        rax = Read<uintptr_t>(rax + 0x9);                 //mov rax, [rax+0x09]
        uintptr_t RSP_0x50;
        RSP_0x50 = 0xA2CEB44D9FB8DC1D;          //mov rax, 0xA2CEB44D9FB8DC1D : RSP+0x50
        rax *= RSP_0x50;                //imul rax, [rsp+0x50]
        r8 *= rax;              //imul r8, rax
        r8 -= r11;              //sub r8, r11
        return r8;
    }
    case 4:
    {
        r10 = Read<uintptr_t>(mb + 0xA4CA102);            //mov r10, [0x0000000002F0D9C1]
        r8 += rbx;              //add r8, rbx
        r8 += rbx;              //add r8, rbx
        rax = 0x3162847D68C255B8;               //mov rax, 0x3162847D68C255B8
        r8 -= rax;              //sub r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x19;           //shr rax, 0x19
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x32;           //shr rax, 0x32
        r8 ^= rax;              //xor r8, rax
        rax = 0x2116B7CA87F505BB;               //mov rax, 0x2116B7CA87F505BB
        r8 *= rax;              //imul r8, rax
        rax = 0xEA83BBA5541DCB75;               //mov rax, 0xEA83BBA5541DCB75
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x12;           //shr rax, 0x12
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x24;           //shr rax, 0x24
        rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
        r8 ^= rax;              //xor r8, rax
        rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
        rcx ^= r10;             //xor rcx, r10
        rcx = _byteswap_uint64(rcx);            //bswap rcx
        r8 *= Read<uintptr_t>(rcx + 0x9);                 //imul r8, [rcx+0x09]
        return r8;
    }
    case 5:
    {
        r10 = Read<uintptr_t>(mb + 0xA4CA102);            //mov r10, [0x0000000002F0D4FF]
        r11 = mb;               //lea r11, [0xFFFFFFFFF8A433EA]
        r8 ^= r11;              //xor r8, r11
        rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
        rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
        rcx ^= r10;             //xor rcx, r10
        rax = rbx;              //mov rax, rbx
        rax = ~rax;             //not rax
        rax -= r11;             //sub rax, r11
        rax += 0xFFFFFFFFC2139BB3;              //add rax, 0xFFFFFFFFC2139BB3
        rcx = _byteswap_uint64(rcx);            //bswap rcx
        r8 += rax;              //add r8, rax
        r8 *= Read<uintptr_t>(rcx + 0x9);                 //imul r8, [rcx+0x09]
        rax = r8;               //mov rax, r8
        rax >>= 0xC;            //shr rax, 0x0C
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x18;           //shr rax, 0x18
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x30;           //shr rax, 0x30
        r8 ^= rax;              //xor r8, rax
        rax = mb + 0x1374C560;          //lea rax, [0x000000000C18F6E1]
        rax = ~rax;             //not rax
        rax += rbx;             //add rax, rbx
        r8 += rax;              //add r8, rax
        rax = 0x9BBE6AE7ED4BB59;                //mov rax, 0x9BBE6AE7ED4BB59
        r8 *= rax;              //imul r8, rax
        rax = 0x71CE8E54E752FAE6;               //mov rax, 0x71CE8E54E752FAE6
        r8 -= rax;              //sub r8, rax
        rax = r11 + 0x67d;              //lea rax, [r11+0x67D]
        rax += rbx;             //add rax, rbx
        r8 ^= rax;              //xor r8, rax
        return r8;
    }
    case 6:
    {
        r10 = Read<uintptr_t>(mb + 0xA4CA102);            //mov r10, [0x0000000002F0CF5A]
        r11 = mb;               //lea r11, [0xFFFFFFFFF8A42E45]
        rax = mb + 0x380D91B1;          //lea rax, [0x0000000030B1BE80]
        rax = ~rax;             //not rax
        rax ^= rbx;             //xor rax, rbx
        r8 ^= rax;              //xor r8, rax
        rax = 0x7E108AAB571C84CF;               //mov rax, 0x7E108AAB571C84CF
        r8 += rax;              //add r8, rax
        rax = 0x67A35786E93EEF30;               //mov rax, 0x67A35786E93EEF30
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x10;           //shr rax, 0x10
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x20;           //shr rax, 0x20
        r8 ^= rax;              //xor r8, rax
        rax = 0x4EFC42E1340DF84F;               //mov rax, 0x4EFC42E1340DF84F
        r8 *= rax;              //imul r8, rax
        rax = 0;                //and rax, 0xFFFFFFFFC0000000
        rax = _rotl64(rax, 0x10);               //rol rax, 0x10
        rax ^= r10;             //xor rax, r10
        rax = _byteswap_uint64(rax);            //bswap rax
        r8 *= Read<uintptr_t>(rax + 0x9);                 //imul r8, [rax+0x09]
        rax = rbx;              //mov rax, rbx
        uintptr_t RSP_0x70;
        RSP_0x70 = mb + 0x322A437D;             //lea rax, [0x000000002ACE718E] : RSP+0x70
        rax ^= RSP_0x70;                //xor rax, [rsp+0x70]
        r8 += rax;              //add r8, rax
        r8 ^= r11;              //xor r8, r11
        return r8;
    }
    case 7:
    {
        r10 = Read<uintptr_t>(mb + 0xA4CA102);            //mov r10, [0x0000000002F0C9BE]
        r11 = mb;               //lea r11, [0xFFFFFFFFF8A428A9]
        r8 += rbx;              //add r8, rbx
        r8 ^= rbx;              //xor r8, rbx
        rax = r11 + 0x673cd4f3;                 //lea rax, [r11+0x673CD4F3]
        rax += rbx;             //add rax, rbx
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x1F;           //shr rax, 0x1F
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
        rax >>= 0x3E;           //shr rax, 0x3E
        rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
        r8 ^= rax;              //xor r8, rax
        rcx ^= r10;             //xor rcx, r10
        rax = 0x7678D1A47475A5D7;               //mov rax, 0x7678D1A47475A5D7
        rcx = _byteswap_uint64(rcx);            //bswap rcx
        r8 *= Read<uintptr_t>(rcx + 0x9);                 //imul r8, [rcx+0x09]
        r8 ^= rax;              //xor r8, rax
        rax = 0x58593DC333358A6F;               //mov rax, 0x58593DC333358A6F
        r8 ^= rax;              //xor r8, rax
        rax = 0x984B8FADB19C1B8B;               //mov rax, 0x984B8FADB19C1B8B
        r8 *= rax;              //imul r8, rax
        return r8;
    }
    case 8:
    {
        r11 = mb;               //lea r11, [0xFFFFFFFFF8A4241E]
        r10 = Read<uintptr_t>(mb + 0xA4CA102);            //mov r10, [0x0000000002F0C4F3]
        rax = r8;               //mov rax, r8
        rax >>= 0x2;            //shr rax, 0x02
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x4;            //shr rax, 0x04
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x8;            //shr rax, 0x08
        r8 ^= rax;              //xor r8, rax
        rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
        rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
        rcx ^= r10;             //xor rcx, r10
        rax = r8;               //mov rax, r8
        rax >>= 0x10;           //shr rax, 0x10
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x20;           //shr rax, 0x20
        rax ^= rbx;             //xor rax, rbx
        r8 ^= rax;              //xor r8, rax
        rax = mb + 0xCAAE;              //lea rax, [0xFFFFFFFFF8A4EABF]
        r8 ^= rax;              //xor r8, rax
        rcx = _byteswap_uint64(rcx);            //bswap rcx
        r8 *= Read<uintptr_t>(rcx + 0x9);                 //imul r8, [rcx+0x09]
        rax = 0xF7BF19C3A8AAF99D;               //mov rax, 0xF7BF19C3A8AAF99D
        r8 *= rax;              //imul r8, rax
        rax = 0x684A1F193BE23CB8;               //mov rax, 0x684A1F193BE23CB8
        r8 += rax;              //add r8, rax
        r8 += r11;              //add r8, r11
        rax = r8;               //mov rax, r8
        rax >>= 0xD;            //shr rax, 0x0D
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x1A;           //shr rax, 0x1A
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x34;           //shr rax, 0x34
        r8 ^= rax;              //xor r8, rax
        rax = 0x235ADD1BCD0E993D;               //mov rax, 0x235ADD1BCD0E993D
        r8 *= rax;              //imul r8, rax
        return r8;
    }
    case 9:
    {
        r11 = mb;               //lea r11, [0xFFFFFFFFF8A41FD8]
        r9 = Read<uintptr_t>(mb + 0xA4CA102);             //mov r9, [0x0000000002F0C07A]
        r8 ^= r11;              //xor r8, r11
        rax = 0;                //and rax, 0xFFFFFFFFC0000000
        rax = _rotl64(rax, 0x10);               //rol rax, 0x10
        rax ^= r9;              //xor rax, r9
        rax = _byteswap_uint64(rax);            //bswap rax
        r8 *= Read<uintptr_t>(rax + 0x9);                 //imul r8, [rax+0x09]
        rax = 0x3FD06965B4FA068B;               //mov rax, 0x3FD06965B4FA068B
        r8 ^= rax;              //xor r8, rax
        rax = 0x99F0BBCA7948EFEB;               //mov rax, 0x99F0BBCA7948EFEB
        r8 *= rax;              //imul r8, rax
        r8 ^= r11;              //xor r8, r11
        rax = r8;               //mov rax, r8
        rax >>= 0xC;            //shr rax, 0x0C
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x18;           //shr rax, 0x18
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x30;           //shr rax, 0x30
        r8 ^= rax;              //xor r8, rax
        r8 -= r11;              //sub r8, r11
        return r8;
    }
    case 10:
    {
        r10 = Read<uintptr_t>(mb + 0xA4CA102);            //mov r10, [0x0000000002F0BC92]
        r11 = mb;               //lea r11, [0xFFFFFFFFF8A41B7D]
        rax = r8;               //mov rax, r8
        rax >>= 0x1A;           //shr rax, 0x1A
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x34;           //shr rax, 0x34
        r8 ^= rax;              //xor r8, rax
        uintptr_t RSP_0x58;
        RSP_0x58 = 0x3637CB8D962E9E56;          //mov rax, 0x3637CB8D962E9E56 : RSP+0x58
        r8 ^= RSP_0x58;                 //xor r8, [rsp+0x58]
        rax = 0;                //and rax, 0xFFFFFFFFC0000000
        rax = _rotl64(rax, 0x10);               //rol rax, 0x10
        rax ^= r10;             //xor rax, r10
        rax = _byteswap_uint64(rax);            //bswap rax
        r8 *= Read<uintptr_t>(rax + 0x9);                 //imul r8, [rax+0x09]
        r8 ^= r11;              //xor r8, r11
        r8 += r11;              //add r8, r11
        rax = r8;               //mov rax, r8
        rax >>= 0xE;            //shr rax, 0x0E
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x1C;           //shr rax, 0x1C
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x38;           //shr rax, 0x38
        r8 ^= rax;              //xor r8, rax
        rax = 0x1FFC253876B4F69B;               //mov rax, 0x1FFC253876B4F69B
        r8 *= rax;              //imul r8, rax
        rax = 0x219ADEEB19368361;               //mov rax, 0x219ADEEB19368361
        r8 -= rax;              //sub r8, rax
        return r8;
    }
    case 11:
    {
        r11 = mb;               //lea r11, [0xFFFFFFFFF8A4173D]
        r9 = Read<uintptr_t>(mb + 0xA4CA102);             //mov r9, [0x0000000002F0B7CE]
        rax = 0x428EA31D565843D4;               //mov rax, 0x428EA31D565843D4
        r8 -= rax;              //sub r8, rax
        rax = r11 + 0xc2b8;             //lea rax, [r11+0xC2B8]
        rax += rbx;             //add rax, rbx
        r8 += rax;              //add r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x11;           //shr rax, 0x11
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x22;           //shr rax, 0x22
        r8 ^= rax;              //xor r8, rax
        r8 += rbx;              //add r8, rbx
        rax = mb + 0x4F7FC7FB;          //lea rax, [0x000000004823DC7E]
        rax -= rbx;             //sub rax, rbx
        r8 += rax;              //add r8, rax
        rax = 0x519A51F23EC7C265;               //mov rax, 0x519A51F23EC7C265
        r8 *= rax;              //imul r8, rax
        rax = 0;                //and rax, 0xFFFFFFFFC0000000
        rax = _rotl64(rax, 0x10);               //rol rax, 0x10
        rax ^= r9;              //xor rax, r9
        rax = _byteswap_uint64(rax);            //bswap rax
        r8 *= Read<uintptr_t>(rax + 0x9);                 //imul r8, [rax+0x09]
        rax = rbx;              //mov rax, rbx
        uintptr_t RSP_0x70;
        RSP_0x70 = mb + 0x557E1EBE;             //lea rax, [0x000000004E2235BE] : RSP+0x70
        rax ^= RSP_0x70;                //xor rax, [rsp+0x70]
        r8 -= rax;              //sub r8, rax
        return r8;
    }
    case 12:
    {
        r11 = mb;               //lea r11, [0xFFFFFFFFF8A4121C]
        r9 = Read<uintptr_t>(mb + 0xA4CA102);             //mov r9, [0x0000000002F0B2AF]
        rax = 0;                //and rax, 0xFFFFFFFFC0000000
        rax = _rotl64(rax, 0x10);               //rol rax, 0x10
        rax ^= r9;              //xor rax, r9
        rax = _byteswap_uint64(rax);            //bswap rax
        r8 *= Read<uintptr_t>(rax + 0x9);                 //imul r8, [rax+0x09]
        r8 ^= r11;              //xor r8, r11
        rax = rbx;              //mov rax, rbx
        rax -= r11;             //sub rax, r11
        rax += 0xFFFFFFFFFFFF60B8;              //add rax, 0xFFFFFFFFFFFF60B8
        r8 += rax;              //add r8, rax
        rax = 0x1C5BFEEDDBF5EB53;               //mov rax, 0x1C5BFEEDDBF5EB53
        r8 *= rax;              //imul r8, rax
        rax = 0x130EFD65B51B3F18;               //mov rax, 0x130EFD65B51B3F18
        r8 += rax;              //add r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0xF;            //shr rax, 0x0F
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x1E;           //shr rax, 0x1E
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x3C;           //shr rax, 0x3C
        r8 ^= rax;              //xor r8, rax
        rax = 0xF2D0C564E6EAF071;               //mov rax, 0xF2D0C564E6EAF071
        r8 *= rax;              //imul r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x26;           //shr rax, 0x26
        r8 ^= rax;              //xor r8, rax
        return r8;
    }
    case 13:
    {
        r11 = mb;               //lea r11, [0xFFFFFFFFF8A40C67]
        r9 = Read<uintptr_t>(mb + 0xA4CA102);             //mov r9, [0x0000000002F0ACC1]
        rax = r8;               //mov rax, r8
        rax >>= 0x26;           //shr rax, 0x26
        r8 ^= rax;              //xor r8, rax
        r8 ^= r11;              //xor r8, r11
        rax = 0x4D78A95661567729;               //mov rax, 0x4D78A95661567729
        r8 *= rax;              //imul r8, rax
        rax = 0x9105F0D673BF690D;               //mov rax, 0x9105F0D673BF690D
        r8 ^= rax;              //xor r8, rax
        rax = r11 + 0x6332c5b8;                 //lea rax, [r11+0x6332C5B8]
        rax += rbx;             //add rax, rbx
        r8 += rax;              //add r8, rax
        r8 ^= rbx;              //xor r8, rbx
        rax = mb + 0x65F4D3CE;          //lea rax, [0x000000005E98DD6B]
        r8 ^= rax;              //xor r8, rax
        rax = 0x8C2C5299E9CEEB07;               //mov rax, 0x8C2C5299E9CEEB07
        r8 ^= rax;              //xor r8, rax
        rax = 0;                //and rax, 0xFFFFFFFFC0000000
        rax = _rotl64(rax, 0x10);               //rol rax, 0x10
        rax ^= r9;              //xor rax, r9
        rax = _byteswap_uint64(rax);            //bswap rax
        r8 *= Read<uintptr_t>(rax + 0x9);                 //imul r8, [rax+0x09]
        return r8;
    }
    case 14:
    {
        r11 = mb;               //lea r11, [0xFFFFFFFFF8A4070B]
        r10 = Read<uintptr_t>(mb + 0xA4CA102);            //mov r10, [0x0000000002F0A788]
        r8 ^= r11;              //xor r8, r11
        rax = 0xB2CB08F70F17ECB9;               //mov rax, 0xB2CB08F70F17ECB9
        r8 *= rax;              //imul r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x20;           //shr rax, 0x20
        r8 ^= rax;              //xor r8, rax
        r8 ^= rbx;              //xor r8, rbx
        rax = 0x5194F48F99B25BB7;               //mov rax, 0x5194F48F99B25BB7
        r8 += rax;              //add r8, rax
        rax = 0x9406961BF3A0B6DB;               //mov rax, 0x9406961BF3A0B6DB
        r8 *= rax;              //imul r8, rax
        rax = rbx;              //mov rax, rbx
        rax = ~rax;             //not rax
        uintptr_t RSP_0x68;
        RSP_0x68 = mb + 0x1FFCB725;             //lea rax, [0x0000000018A0BE29] : RSP+0x68
        rax *= RSP_0x68;                //imul rax, [rsp+0x68]
        r8 ^= rax;              //xor r8, rax
        rax = 0;                //and rax, 0xFFFFFFFFC0000000
        rax = _rotl64(rax, 0x10);               //rol rax, 0x10
        rax ^= r10;             //xor rax, r10
        rax = _byteswap_uint64(rax);            //bswap rax
        r8 *= Read<uintptr_t>(rax + 0x9);                 //imul r8, [rax+0x09]
        return r8;
    }
    case 15:
    {
        r10 = Read<uintptr_t>(mb + 0xA4CA102);            //mov r10, [0x0000000002F0A2EE]
        rcx = mb + 0xF5C3;              //lea rcx, [0xFFFFFFFFF8A4F715]
        rax = rcx;              //mov rax, rcx
        rax = ~rax;             //not rax
        rax -= rbx;             //sub rax, rbx
        r8 += rax;              //add r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x7;            //shr rax, 0x07
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0xE;            //shr rax, 0x0E
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x1C;           //shr rax, 0x1C
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x38;           //shr rax, 0x38
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x12;           //shr rax, 0x12
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x24;           //shr rax, 0x24
        r8 ^= rax;              //xor r8, rax
        rax = 0;                //and rax, 0xFFFFFFFFC0000000
        rax = _rotl64(rax, 0x10);               //rol rax, 0x10
        rax ^= r10;             //xor rax, r10
        rax = _byteswap_uint64(rax);            //bswap rax
        r8 *= Read<uintptr_t>(rax + 0x9);                 //imul r8, [rax+0x09]
        rax = r8;               //mov rax, r8
        rax >>= 0x18;           //shr rax, 0x18
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x30;           //shr rax, 0x30
        r8 ^= rax;              //xor r8, rax
        rax = 0x575A9D2C3873BDEC;               //mov rax, 0x575A9D2C3873BDEC
        r8 ^= rax;              //xor r8, rax
        rax = 0xAE0D90C9AC20C2A5;               //mov rax, 0xAE0D90C9AC20C2A5
        r8 *= rax;              //imul r8, rax
        rax = 0xEB1F765CE2645B5;                //mov rax, 0xEB1F765CE2645B5
        r8 += rax;              //add r8, rax
        return r8;
    }
    }
}
uint64_t get_cbuf(QWORD BaseAddress, QWORD Peb)
{
    auto mb = BaseAddress;
    uint64_t rax = mb, rbx = mb, rcx = mb, rdx = mb, rdi = mb, rsi = mb, r8 = mb, r9 = mb, r10 = mb, r11 = mb, r12 = mb, r13 = mb, r14 = mb, r15 = mb;
    rcx = Read<uintptr_t>(mb + 0xDCB50A0);
    if (!rcx)
        return rcx;
    rbx = Peb;              //mov rbx, gs:[rdx]
    rdx = rbx;              //mov rdx, rbx
    rdx = _rotr64(rdx, 0x11);               //ror rdx, 0x11
    rdx &= 0xF;
    switch (rdx) {
    case 0:
    {
        r11 = mb;               //lea r11, [0xFFFFFFFFFC8F4544]
        r14 = mb + 0x354E5E87;          //lea r14, [0x0000000031DDA3BC]
        r10 = Read<uintptr_t>(mb + 0xA4CA154);            //mov r10, [0x0000000006DBE5E7]
        rax = 0xE72F135C691F6457;               //mov rax, 0xE72F135C691F6457
        rcx *= rax;             //imul rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0x16;           //shr rax, 0x16
        rcx ^= rax;             //xor rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0x2C;           //shr rax, 0x2C
        rcx ^= rax;             //xor rcx, rax
        rcx *= Read<uintptr_t>(r10 + 0x15);               //imul rcx, [r10+0x15]
        rdx = rbx;              //mov rdx, rbx
        rdx = ~rdx;             //not rdx
        rdx *= r14;             //imul rdx, r14
        rax = 0x70F40A95F4672FE0;               //mov rax, 0x70F40A95F4672FE0
        rcx += rax;             //add rcx, rax
        rcx += rdx;             //add rcx, rdx
        rcx ^= r11;             //xor rcx, r11
        rcx -= r11;             //sub rcx, r11
        rcx ^= rbx;             //xor rcx, rbx
        return rcx;
    }
    case 1:
    {
        r11 = mb;               //lea r11, [0xFFFFFFFFFC8F40D6]
        r10 = Read<uintptr_t>(mb + 0xA4CA154);            //mov r10, [0x0000000006DBE176]
        rax = 0x1668C6FF51EAF4ED;               //mov rax, 0x1668C6FF51EAF4ED
        rcx ^= rax;             //xor rcx, rax
        rax = 0xCBAB21349DCAE5FD;               //mov rax, 0xCBAB21349DCAE5FD
        rcx *= rax;             //imul rcx, rax
        rax = mb + 0x75D8D7AF;          //lea rax, [0x000000007268139B]
        rcx -= rbx;             //sub rcx, rbx
        rcx += rax;             //add rcx, rax
        rcx *= Read<uintptr_t>(r10 + 0x15);               //imul rcx, [r10+0x15]
        rax = rcx;              //mov rax, rcx
        rax >>= 0x13;           //shr rax, 0x13
        rcx ^= rax;             //xor rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0x26;           //shr rax, 0x26
        rcx ^= rax;             //xor rcx, rax
        rcx += 0xFFFFFFFFFFFF50E3;              //add rcx, 0xFFFFFFFFFFFF50E3
        rax = rbx;              //mov rax, rbx
        rax -= r11;             //sub rax, r11
        rcx += rax;             //add rcx, rax
        rax = 0xFFFFFFFFEFE8B772;               //mov rax, 0xFFFFFFFFEFE8B772
        rax -= rbx;             //sub rax, rbx
        rax -= r11;             //sub rax, r11
        rcx += rax;             //add rcx, rax
        rax = r11 + 0xa832;             //lea rax, [r11+0xA832]
        rax += rbx;             //add rax, rbx
        rcx ^= rax;             //xor rcx, rax
        return rcx;
    }
    case 2:
    {
        r14 = mb + 0x53BD;              //lea r14, [0xFFFFFFFFFC8F8F91]
        r10 = Read<uintptr_t>(mb + 0xA4CA154);            //mov r10, [0x0000000006DBDCBD]
        rcx *= Read<uintptr_t>(r10 + 0x15);               //imul rcx, [r10+0x15]
        rax = rcx;              //mov rax, rcx
        rax >>= 0xF;            //shr rax, 0x0F
        rcx ^= rax;             //xor rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0x1E;           //shr rax, 0x1E
        rcx ^= rax;             //xor rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0x3C;           //shr rax, 0x3C
        rcx ^= rax;             //xor rcx, rax
        rcx ^= rbx;             //xor rcx, rbx
        rax = 0x1D05435B84E25A51;               //mov rax, 0x1D05435B84E25A51
        rcx *= rax;             //imul rcx, rax
        rax = 0xF4AF956830B15CEB;               //mov rax, 0xF4AF956830B15CEB
        rcx *= rax;             //imul rcx, rax
        rcx ^= rbx;             //xor rcx, rbx
        rdx = r14;              //mov rdx, r14
        rdx = ~rdx;             //not rdx
        rdx *= rbx;             //imul rdx, rbx
        rcx += rdx;             //add rcx, rdx
        rax = 0x735996108078DA8A;               //mov rax, 0x735996108078DA8A
        rcx ^= rax;             //xor rcx, rax
        return rcx;
    }
    case 3:
    {
        r11 = mb;               //lea r11, [0xFFFFFFFFFC8F374D]
        r14 = mb + 0x1CCA166F;          //lea r14, [0x0000000019594DAD]
        rdi = mb + 0x4EED12A6;          //lea rdi, [0x000000004B7C49D5]
        r9 = Read<uintptr_t>(mb + 0xA4CA154);             //mov r9, [0x0000000006DBD7F1]
        rcx ^= rbx;             //xor rcx, rbx
        rcx *= Read<uintptr_t>(r9 + 0x15);                //imul rcx, [r9+0x15]
        rax = rcx;              //mov rax, rcx
        rax >>= 0x18;           //shr rax, 0x18
        rcx ^= rax;             //xor rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0x30;           //shr rax, 0x30
        rcx ^= rax;             //xor rcx, rax
        rax = rdi;              //mov rax, rdi
        rax = ~rax;             //not rax
        rax += rbx;             //add rax, rbx
        rcx ^= rax;             //xor rcx, rax
        rax = 0x7810FF41FFDDD3A7;               //mov rax, 0x7810FF41FFDDD3A7
        rcx *= rax;             //imul rcx, rax
        rax = r14;              //mov rax, r14
        rcx -= rbx;             //sub rcx, rbx
        rax = ~rax;             //not rax
        rcx += rax;             //add rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0xF;            //shr rax, 0x0F
        rcx ^= rax;             //xor rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0x1E;           //shr rax, 0x1E
        rcx ^= rax;             //xor rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0x3C;           //shr rax, 0x3C
        rcx ^= rax;             //xor rcx, rax
        rcx += r11;             //add rcx, r11
        return rcx;
    }
    case 4:
    {
        r11 = mb;               //lea r11, [0xFFFFFFFFFC8F32DB]
        rdi = mb + 0x1626BF57;          //lea rdi, [0x0000000012B5F223]
        r9 = Read<uintptr_t>(mb + 0xA4CA154);             //mov r9, [0x0000000006DBD389]
        rax = 0xFFFFFFFF882A8DC3;               //mov rax, 0xFFFFFFFF882A8DC3
        rax -= rbx;             //sub rax, rbx
        rax -= r11;             //sub rax, r11
        rcx += rax;             //add rcx, rax
        rax = rbx;              //mov rax, rbx
        rax ^= rdi;             //xor rax, rdi
        rcx -= rax;             //sub rcx, rax
        rax = mb + 0x4BC19201;          //lea rax, [0x000000004850C0B6]
        rax = ~rax;             //not rax
        rax *= rbx;             //imul rax, rbx
        rcx ^= rax;             //xor rcx, rax
        rax = 0x2C74441176B5ADA9;               //mov rax, 0x2C74441176B5ADA9
        rcx *= rax;             //imul rcx, rax
        rax = 0x3DE195FBD6C9A34F;               //mov rax, 0x3DE195FBD6C9A34F
        rcx -= rax;             //sub rcx, rax
        rcx *= Read<uintptr_t>(r9 + 0x15);                //imul rcx, [r9+0x15]
        rax = rcx;              //mov rax, rcx
        rax >>= 0x1F;           //shr rax, 0x1F
        rcx ^= rax;             //xor rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0x3E;           //shr rax, 0x3E
        rcx ^= rax;             //xor rcx, rax
        rax = 0x2C73B29314C69FA8;               //mov rax, 0x2C73B29314C69FA8
        rcx -= rax;             //sub rcx, rax
        return rcx;
    }
    case 5:
    {
        r11 = mb;               //lea r11, [0xFFFFFFFFFC8F2E91]
        r13 = mb + 0x73D80157;          //lea r13, [0x0000000070672FD9]
        r12 = mb + 0x5D6C5F40;          //lea r12, [0x0000000059FB8DB3]
        r10 = Read<uintptr_t>(mb + 0xA4CA154);            //mov r10, [0x0000000006DBCF7B]
        rdx = mb + 0x57036ABA;          //lea rdx, [0x00000000539298AD]
        rax = rbx;              //mov rax, rbx
        rax ^= r13;             //xor rax, r13
        rcx -= rax;             //sub rcx, rax
        rcx ^= rbx;             //xor rcx, rbx
        rcx ^= rdx;             //xor rcx, rdx
        rax = 0x28E1BFE2485F389;                //mov rax, 0x28E1BFE2485F389
        rcx *= rax;             //imul rcx, rax
        rcx -= r11;             //sub rcx, r11
        rcx *= Read<uintptr_t>(r10 + 0x15);               //imul rcx, [r10+0x15]
        rax = rcx;              //mov rax, rcx
        rax >>= 0x9;            //shr rax, 0x09
        rcx ^= rax;             //xor rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0x12;           //shr rax, 0x12
        rcx ^= rax;             //xor rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0x24;           //shr rax, 0x24
        rcx ^= rax;             //xor rcx, rax
        rax = r12;              //mov rax, r12
        rax -= rbx;             //sub rax, rbx
        rcx += rax;             //add rcx, rax
        return rcx;
    }
    case 6:
    {
        r11 = mb;               //lea r11, [0xFFFFFFFFFC8F2A39]
        r9 = Read<uintptr_t>(mb + 0xA4CA154);             //mov r9, [0x0000000006DBCADB]
        rcx *= Read<uintptr_t>(r9 + 0x15);                //imul rcx, [r9+0x15]
        rcx += rbx;             //add rcx, rbx
        rax = 0x1DD936FEDD6097DF;               //mov rax, 0x1DD936FEDD6097DF
        rcx *= rax;             //imul rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0xB;            //shr rax, 0x0B
        rcx ^= rax;             //xor rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0x16;           //shr rax, 0x16
        rcx ^= rax;             //xor rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0x2C;           //shr rax, 0x2C
        rcx ^= rax;             //xor rcx, rax
        rcx -= r11;             //sub rcx, r11
        rax = 0x34560D367AE64895;               //mov rax, 0x34560D367AE64895
        rcx ^= rax;             //xor rcx, rax
        rax = rbx;              //mov rax, rbx
        rax -= r11;             //sub rax, r11
        rax += 0xFFFFFFFFFFFF2611;              //add rax, 0xFFFFFFFFFFFF2611
        rcx += rax;             //add rcx, rax
        rax = r11 + 0xbb8d;             //lea rax, [r11+0xBB8D]
        rax += rbx;             //add rax, rbx
        rcx ^= rax;             //xor rcx, rax
        return rcx;
    }
    case 7:
    {
        r11 = mb;               //lea r11, [0xFFFFFFFFFC8F252E]
        r14 = mb + 0x58CC7A9E;          //lea r14, [0x00000000555B9FBD]
        rdx = Read<uintptr_t>(mb + 0xA4CA154);            //mov rdx, [0x0000000006DBC616]
        rcx *= Read<uintptr_t>(rdx + 0x15);               //imul rcx, [rdx+0x15]
        rax = rcx;              //mov rax, rcx
        rax >>= 0xD;            //shr rax, 0x0D
        rcx ^= rax;             //xor rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0x1A;           //shr rax, 0x1A
        rcx ^= rax;             //xor rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0x34;           //shr rax, 0x34
        rcx ^= rax;             //xor rcx, rax
        rax = 0x179786D7FD3E3AA7;               //mov rax, 0x179786D7FD3E3AA7
        rcx -= rax;             //sub rcx, rax
        rcx += r11;             //add rcx, r11
        rax = 0xB0661A2AD1145245;               //mov rax, 0xB0661A2AD1145245
        rcx *= rax;             //imul rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0x1F;           //shr rax, 0x1F
        rcx ^= rax;             //xor rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0x3E;           //shr rax, 0x3E
        rcx ^= rax;             //xor rcx, rax
        rax = 0xE58ACD988211E53C;               //mov rax, 0xE58ACD988211E53C
        rcx ^= rax;             //xor rcx, rax
        rcx ^= rbx;             //xor rcx, rbx
        rcx ^= r14;             //xor rcx, r14
        return rcx;
    }
    case 8:
    {
        r11 = mb;               //lea r11, [0xFFFFFFFFFC8F20C4]
        r10 = Read<uintptr_t>(mb + 0xA4CA154);            //mov r10, [0x0000000006DBC1AD]
        rdx = rbx;              //mov rdx, rbx
        rdx = ~rdx;             //not rdx
        rax = rcx;              //mov rax, rcx
        rdx -= r11;             //sub rdx, r11
        rax *= Read<uintptr_t>(r10 + 0x15);               //imul rax, [r10+0x15]
        rcx = rdx + 0xffffffffffffff1e;                 //lea rcx, [rdx-0xE2]
        rcx ^= rax;             //xor rcx, rax
        rax = rbx + 0x1;                //lea rax, [rbx+0x01]
        uintptr_t RSP_0x70;
        RSP_0x70 = mb + 0x3541;                 //lea rax, [0xFFFFFFFFFC8F5550] : RSP+0x70
        rax *= RSP_0x70;                //imul rax, [rsp+0x70]
        rax += rbx;             //add rax, rbx
        rcx += rax;             //add rcx, rax
        rax = 0x1734D2140DB802AB;               //mov rax, 0x1734D2140DB802AB
        rcx ^= rax;             //xor rcx, rax
        rax = 0x517DAA2368CED562;               //mov rax, 0x517DAA2368CED562
        rcx += rax;             //add rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0x22;           //shr rax, 0x22
        rcx ^= rax;             //xor rcx, rax
        rax = 0xAD6A2DA132AB35B5;               //mov rax, 0xAD6A2DA132AB35B5
        rcx *= rax;             //imul rcx, rax
        return rcx;
    }
    case 9:
    {
        r11 = mb;               //lea r11, [0xFFFFFFFFFC8F1BE3]
        r14 = mb + 0x31738B1E;          //lea r14, [0x000000002E02A6F2]
        r9 = Read<uintptr_t>(mb + 0xA4CA154);             //mov r9, [0x0000000006DBBC4A]
        rax = 0xFFFFFFFFFFFF51A4;               //mov rax, 0xFFFFFFFFFFFF51A4
        rax -= rbx;             //sub rax, rbx
        rax -= r11;             //sub rax, r11
        rcx += rax;             //add rcx, rax
        uintptr_t RSP_0x28;
        RSP_0x28 = 0xD3E0A58FC8956403;          //mov rax, 0xD3E0A58FC8956403 : RSP+0x28
        rcx *= RSP_0x28;                //imul rcx, [rsp+0x28]
        rax = r14;              //mov rax, r14
        rax ^= rbx;             //xor rax, rbx
        rcx -= rax;             //sub rcx, rax
        rcx *= Read<uintptr_t>(r9 + 0x15);                //imul rcx, [r9+0x15]
        rcx ^= rbx;             //xor rcx, rbx
        rax = rbx + r11 * 1;            //lea rax, [rbx+r11*1]
        rcx -= rax;             //sub rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0xB;            //shr rax, 0x0B
        rcx ^= rax;             //xor rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0x16;           //shr rax, 0x16
        rcx ^= rax;             //xor rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0x2C;           //shr rax, 0x2C
        rcx ^= rax;             //xor rcx, rax
        return rcx;
    }
    case 10:
    {
        r14 = mb + 0xA0C9;              //lea r14, [0xFFFFFFFFFC8FB784]
        rdi = mb + 0x2276;              //lea rdi, [0xFFFFFFFFFC8F3922]
        r10 = Read<uintptr_t>(mb + 0xA4CA154);            //mov r10, [0x0000000006DBB775]
        rax = rcx;              //mov rax, rcx
        rax >>= 0x23;           //shr rax, 0x23
        rax ^= rcx;             //xor rax, rcx
        rcx = r14;              //mov rcx, r14
        rax += rbx;             //add rax, rbx
        rcx ^= rbx;             //xor rcx, rbx
        rcx += rax;             //add rcx, rax
        rcx *= Read<uintptr_t>(r10 + 0x15);               //imul rcx, [r10+0x15]
        rax = 0x381651707B692F41;               //mov rax, 0x381651707B692F41
        rcx *= rax;             //imul rcx, rax
        rax = rdi;              //mov rax, rdi
        rax ^= rbx;             //xor rax, rbx
        rcx ^= rax;             //xor rcx, rax
        rax = 0x56D35D82031EEB97;               //mov rax, 0x56D35D82031EEB97
        rcx -= rax;             //sub rcx, rax
        return rcx;
    }
    case 11:
    {
        rdi = mb + 0xEEB;               //lea rdi, [0xFFFFFFFFFC8F2122]
        r14 = mb + 0x47696E13;          //lea r14, [0x0000000043F8803B]
        r12 = mb + 0xE292;              //lea r12, [0xFFFFFFFFFC8FF4AB]
        r10 = Read<uintptr_t>(mb + 0xA4CA154);            //mov r10, [0x0000000006DBB2F0]
        rcx *= Read<uintptr_t>(r10 + 0x15);               //imul rcx, [r10+0x15]
        rax = rcx;              //mov rax, rcx
        rax >>= 0x12;           //shr rax, 0x12
        rcx ^= rax;             //xor rcx, rax
        rdx = mb + 0x2C830BF4;          //lea rdx, [0x0000000029121AF5]
        rdx += rbx;             //add rdx, rbx
        rax = rcx;              //mov rax, rcx
        rax >>= 0x24;           //shr rax, 0x24
        rdx ^= rax;             //xor rdx, rax
        rax = 0x292F3B40A9250B2;                //mov rax, 0x292F3B40A9250B2
        rdx ^= r12;             //xor rdx, r12
        rdx ^= rbx;             //xor rdx, rbx
        rcx ^= rdx;             //xor rcx, rdx
        rcx ^= rax;             //xor rcx, rax
        rax = 0xC5930A29A7EFC49F;               //mov rax, 0xC5930A29A7EFC49F
        rcx *= rax;             //imul rcx, rax
        rax = rbx + rdi * 1;            //lea rax, [rbx+rdi*1]
        rcx ^= rax;             //xor rcx, rax
        rax = rbx + r14 * 1;            //lea rax, [rbx+r14*1]
        rcx += rax;             //add rcx, rax
        return rcx;
    }
    case 12:
    {
        r11 = mb;               //lea r11, [0xFFFFFFFFFC8F0D9D]
        r10 = Read<uintptr_t>(mb + 0xA4CA154);            //mov r10, [0x0000000006DBAE87]
        r14 = mb + 0x66E3EE74;          //lea r14, [0x000000006372FB8C]
        rcx ^= r11;             //xor rcx, r11
        rax = 0x6ACDE02D21D7B604;               //mov rax, 0x6ACDE02D21D7B604
        rcx += rax;             //add rcx, rax
        rcx *= Read<uintptr_t>(r10 + 0x15);               //imul rcx, [r10+0x15]
        rax = 0x3EF7958FDF3B3A5A;               //mov rax, 0x3EF7958FDF3B3A5A
        rcx ^= rax;             //xor rcx, rax
        rdx = rbx + r14 * 1;            //lea rdx, [rbx+r14*1]
        rax = rcx;              //mov rax, rcx
        rcx = 0x97808A3F49B790F;                //mov rcx, 0x97808A3F49B790F
        rax *= rcx;             //imul rax, rcx
        rcx = rdx;              //mov rcx, rdx
        rcx ^= rax;             //xor rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0x18;           //shr rax, 0x18
        rcx ^= rax;             //xor rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0x30;           //shr rax, 0x30
        rcx ^= rax;             //xor rcx, rax
        rax = mb + 0xCE5F;              //lea rax, [0xFFFFFFFFFC8FD976]
        rax = ~rax;             //not rax
        rax *= rbx;             //imul rax, rbx
        rcx ^= rax;             //xor rcx, rax
        return rcx;
    }
    case 13:
    {
        r14 = mb + 0x73A4C4D0;          //lea r14, [0x000000007033CE4A]
        r9 = Read<uintptr_t>(mb + 0xA4CA154);             //mov r9, [0x0000000006DBAA29]
        rax = rbx;              //mov rax, rbx
        rax = ~rax;             //not rax
        uintptr_t RSP_0x28;
        RSP_0x28 = mb + 0x4EC2;                 //lea rax, [0xFFFFFFFFFC8F585A] : RSP+0x28
        rax += RSP_0x28;                //add rax, [rsp+0x28]
        rcx ^= rax;             //xor rcx, rax
        rax = 0x472D432331AB59D7;               //mov rax, 0x472D432331AB59D7
        rcx *= rax;             //imul rcx, rax
        rax = r14;              //mov rax, r14
        rax ^= rbx;             //xor rax, rbx
        rcx -= rax;             //sub rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0x22;           //shr rax, 0x22
        rcx ^= rax;             //xor rcx, rax
        rax = 0x48263A1870305F6A;               //mov rax, 0x48263A1870305F6A
        rcx *= Read<uintptr_t>(r9 + 0x15);                //imul rcx, [r9+0x15]
        rcx += rax;             //add rcx, rax
        rax = 0x2305A6BE0DD19F9;                //mov rax, 0x2305A6BE0DD19F9
        rcx += rax;             //add rcx, rax
        rcx -= rbx;             //sub rcx, rbx
        return rcx;
    }
    case 14:
    {
        r11 = mb;               //lea r11, [0xFFFFFFFFFC8F04A2]
        r14 = mb + 0xE1DC;              //lea r14, [0xFFFFFFFFFC8FE66F]
        r9 = Read<uintptr_t>(mb + 0xA4CA154);             //mov r9, [0x0000000006DBA54D]
        rax = r14;              //mov rax, r14
        rax ^= rbx;             //xor rax, rbx
        rcx -= rax;             //sub rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0x14;           //shr rax, 0x14
        rcx ^= rax;             //xor rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0x28;           //shr rax, 0x28
        rcx ^= rax;             //xor rcx, rax
        rax = 0xB12797F751D3F65;                //mov rax, 0xB12797F751D3F65
        rcx *= rax;             //imul rcx, rax
        rcx -= rbx;             //sub rcx, rbx
        rax = 0x118F69A46AC5FA46;               //mov rax, 0x118F69A46AC5FA46
        rcx += rax;             //add rcx, rax
        rcx += r11;             //add rcx, r11
        rax = 0x355CC9B2B3A45275;               //mov rax, 0x355CC9B2B3A45275
        rcx *= rax;             //imul rcx, rax
        rcx *= Read<uintptr_t>(r9 + 0x15);                //imul rcx, [r9+0x15]
        return rcx;
    }
    case 15:
    {
        rdi = mb + 0xD541;              //lea rdi, [0xFFFFFFFFFC8FD5BA]
        r10 = Read<uintptr_t>(mb + 0xA4CA154);            //mov r10, [0x0000000006DBA104]
        rax = rcx;              //mov rax, rcx
        rax >>= 0x1E;           //shr rax, 0x1E
        rcx ^= rax;             //xor rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0x3C;           //shr rax, 0x3C
        rcx ^= rax;             //xor rcx, rax
        rcx += rbx;             //add rcx, rbx
        rax = 0xAD2409B78F36A2DB;               //mov rax, 0xAD2409B78F36A2DB
        rcx *= rax;             //imul rcx, rax
        rax = 0x447D3D2BAC938F13;               //mov rax, 0x447D3D2BAC938F13
        rcx += rax;             //add rcx, rax
        rax = rdi;              //mov rax, rdi
        rax ^= rbx;             //xor rax, rbx
        rcx ^= rax;             //xor rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0x4;            //shr rax, 0x04
        rcx ^= rax;             //xor rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0x8;            //shr rax, 0x08
        rcx ^= rax;             //xor rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0x10;           //shr rax, 0x10
        rcx ^= rax;             //xor rcx, rax
        rax = rcx;              //mov rax, rcx
        rax >>= 0x20;           //shr rax, 0x20
        rcx ^= rax;             //xor rcx, rax
        rcx *= Read<uintptr_t>(r10 + 0x15);               //imul rcx, [r10+0x15]
        rax = 0x1B76B4458D25A156;               //mov rax, 0x1B76B4458D25A156
        rcx += rax;             //add rcx, rax
        return rcx;
    }
    }
}
uint64_t get_bone_ptr(QWORD BaseAddress, QWORD Peb)
{
    auto mb = BaseAddress;
    uint64_t rax = mb, rbx = mb, rcx = mb, rdx = mb, rdi = mb, rsi = mb, r8 = mb, r9 = mb, r10 = mb, r11 = mb, r12 = mb, r13 = mb, r14 = mb, r15 = mb;
    rax = Read<uintptr_t>(mb + 0xDE0EC68);
    if (!rax)
        return rax;
    r10 = Peb;              //mov r10, gs:[rcx]
    rcx = r10;              //mov rcx, r10
    rcx = _rotr64(rcx, 0x16);               //ror rcx, 0x16
    rcx &= 0xF;
    switch (rcx) {
    case 0:
    {
        rbx = mb;               //lea rbx, [0xFFFFFFFFFD342025]
        r9 = Read<uintptr_t>(mb + 0xA4CA1E4);             //mov r9, [0x000000000780C164]
        rcx = 0xACB419C98FC6FF1B;               //mov rcx, 0xACB419C98FC6FF1B
        rax ^= rcx;             //xor rax, rcx
        rcx = 0xE876F381616C467B;               //mov rcx, 0xE876F381616C467B
        rax *= rcx;             //imul rax, rcx
        rax += rbx;             //add rax, rbx
        rax ^= rbx;             //xor rax, rbx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x1A;           //shr rcx, 0x1A
        rax ^= rcx;             //xor rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x34;           //shr rcx, 0x34
        rax ^= rcx;             //xor rax, rcx
        rcx = 0x8A50BAFD723F8FC;                //mov rcx, 0x8A50BAFD723F8FC
        rax += r10;             //add rax, r10
        rax ^= rcx;             //xor rax, rcx
        rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
        rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
        rcx ^= r9;              //xor rcx, r9
        rcx = ~rcx;             //not rcx
        rax *= Read<uintptr_t>(rcx + 0x13);               //imul rax, [rcx+0x13]
        return rax;
    }
    case 1:
    {
        rbx = mb;               //lea rbx, [0xFFFFFFFFFD341B6A]
        r12 = mb + 0x3CC42EFF;          //lea r12, [0x0000000039F84A5A]
        r11 = Read<uintptr_t>(mb + 0xA4CA1E4);            //mov r11, [0x000000000780BCF4]
        rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
        rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
        rcx ^= r11;             //xor rcx, r11
        rcx = ~rcx;             //not rcx
        rax *= Read<uintptr_t>(rcx + 0x13);               //imul rax, [rcx+0x13]
        rcx = 0xD5776FB87F169C72;               //mov rcx, 0xD5776FB87F169C72
        rax ^= rcx;             //xor rax, rcx
        rcx = r10 + 0x1;                //lea rcx, [r10+0x01]
        rcx *= r12;             //imul rcx, r12
        rcx += r10;             //add rcx, r10
        rax += rcx;             //add rax, rcx
        rcx = 0xFFFFFFFFCEE5B08A;               //mov rcx, 0xFFFFFFFFCEE5B08A
        rcx -= r10;             //sub rcx, r10
        rcx -= rbx;             //sub rcx, rbx
        rax += rcx;             //add rax, rcx
        rcx = 0x1C3EA404CD52078F;               //mov rcx, 0x1C3EA404CD52078F
        rax *= rcx;             //imul rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x1C;           //shr rcx, 0x1C
        rax ^= rcx;             //xor rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x38;           //shr rcx, 0x38
        rax ^= rcx;             //xor rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x9;            //shr rcx, 0x09
        rax ^= rcx;             //xor rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x12;           //shr rcx, 0x12
        rax ^= rcx;             //xor rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x24;           //shr rcx, 0x24
        rax ^= rcx;             //xor rax, rcx
        return rax;
    }
    case 2:
    {
        r15 = mb + 0x45F68597;          //lea r15, [0x00000000432A9C0B]
        r11 = Read<uintptr_t>(mb + 0xA4CA1E4);            //mov r11, [0x000000000780B7FF]
        rax -= r10;             //sub rax, r10
        rcx = rax;              //mov rcx, rax
        rdx = r15;              //mov rdx, r15
        rcx >>= 0x1F;           //shr rcx, 0x1F
        rdx = ~rdx;             //not rdx
        rax ^= rcx;             //xor rax, rcx
        rdx ^= r10;             //xor rdx, r10
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x3E;           //shr rcx, 0x3E
        rax ^= rcx;             //xor rax, rcx
        rax -= rdx;             //sub rax, rdx
        rcx = mb + 0x7F9A0137;          //lea rcx, [0x000000007CCE1501]
        rcx = ~rcx;             //not rcx
        rcx *= r10;             //imul rcx, r10
        rax += rcx;             //add rax, rcx
        rcx = 0xACD30D0E0CB3B609;               //mov rcx, 0xACD30D0E0CB3B609
        rax *= rcx;             //imul rax, rcx
        rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
        rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
        rcx ^= r11;             //xor rcx, r11
        rcx = ~rcx;             //not rcx
        rax *= Read<uintptr_t>(rcx + 0x13);               //imul rax, [rcx+0x13]
        rcx = 0xED4CD6EB4902A2CF;               //mov rcx, 0xED4CD6EB4902A2CF
        rax *= rcx;             //imul rax, rcx
        rcx = 0x58222EBCB451547;                //mov rcx, 0x58222EBCB451547
        rax -= rcx;             //sub rax, rcx
        return rax;
    }
    case 3:
    {
        rbx = mb;               //lea rbx, [0xFFFFFFFFFD3411A1]
        r15 = mb + 0x3B5B4CE9;          //lea r15, [0x00000000388F5E7B]
        r12 = mb + 0x6136;              //lea r12, [0xFFFFFFFFFD3472B9]
        r11 = Read<uintptr_t>(mb + 0xA4CA1E4);            //mov r11, [0x000000000780B329]
        uintptr_t RSP_0x70;
        RSP_0x70 = 0x48710BD74BE7A67;           //mov rcx, 0x48710BD74BE7A67 : RSP+0x70
        rax *= RSP_0x70;                //imul rax, [rsp+0x70]
        rcx = r12;              //mov rcx, r12
        rcx = ~rcx;             //not rcx
        rcx ^= r10;             //xor rcx, r10
        rax -= rcx;             //sub rax, rcx
        rax -= rbx;             //sub rax, rbx
        rcx = r10;              //mov rcx, r10
        rcx ^= r15;             //xor rcx, r15
        rax += rcx;             //add rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x28;           //shr rcx, 0x28
        rdx = 0;                //and rdx, 0xFFFFFFFFC0000000
        rax ^= rcx;             //xor rax, rcx
        rdx = _rotl64(rdx, 0x10);               //rol rdx, 0x10
        rdx ^= r11;             //xor rdx, r11
        rdx = ~rdx;             //not rdx
        rax *= Read<uintptr_t>(rdx + 0x13);               //imul rax, [rdx+0x13]
        rcx = 0xF1760FA9D50E29D9;               //mov rcx, 0xF1760FA9D50E29D9
        rax *= rcx;             //imul rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x26;           //shr rcx, 0x26
        rax ^= rcx;             //xor rax, rcx
        return rax;
    }
    case 4:
    {
        rbx = mb;               //lea rbx, [0xFFFFFFFFFD340CDC]
        r15 = mb + 0x1159;              //lea r15, [0xFFFFFFFFFD341E26]
        r9 = Read<uintptr_t>(mb + 0xA4CA1E4);             //mov r9, [0x000000000780AE00]
        rax ^= r15;             //xor rax, r15
        rcx = 0x46C79791C061B179;               //mov rcx, 0x46C79791C061B179
        rax *= rcx;             //imul rax, rcx
        rax -= rbx;             //sub rax, rbx
        rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
        rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
        rcx ^= r9;              //xor rcx, r9
        rcx = ~rcx;             //not rcx
        rax *= Read<uintptr_t>(rcx + 0x13);               //imul rax, [rcx+0x13]
        rcx = 0x7E856C7DFAD163F2;               //mov rcx, 0x7E856C7DFAD163F2
        rax ^= rcx;             //xor rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x21;           //shr rcx, 0x21
        rax ^= rcx;             //xor rax, rcx
        rcx = 0xE2741BA015D87134;               //mov rcx, 0xE2741BA015D87134
        rax ^= rcx;             //xor rax, rcx
        return rax;
    }
    case 5:
    {
        r14 = mb + 0x5C092D57;          //lea r14, [0x00000000593D3572]
        r9 = Read<uintptr_t>(mb + 0xA4CA1E4);             //mov r9, [0x000000000780A92F]
        rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
        rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
        rcx ^= r9;              //xor rcx, r9
        rcx = ~rcx;             //not rcx
        rax *= Read<uintptr_t>(rcx + 0x13);               //imul rax, [rcx+0x13]
        rax -= r10;             //sub rax, r10
        rcx = r10 + 0x1;                //lea rcx, [r10+0x01]
        rcx *= r14;             //imul rcx, r14
        rax += rcx;             //add rax, rcx
        rcx = 0xD25A6F4DBF815BDB;               //mov rcx, 0xD25A6F4DBF815BDB
        rax *= rcx;             //imul rax, rcx
        rcx = 0x8F98A261B2CD12C1;               //mov rcx, 0x8F98A261B2CD12C1
        rax *= rcx;             //imul rax, rcx
        rcx = 0xB4F7E2E4B937DB54;               //mov rcx, 0xB4F7E2E4B937DB54
        rax ^= rcx;             //xor rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x25;           //shr rcx, 0x25
        rax ^= rcx;             //xor rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x22;           //shr rcx, 0x22
        rax ^= rcx;             //xor rax, rcx
        return rax;
    }
    case 6:
    {
        rbx = mb;               //lea rbx, [0xFFFFFFFFFD3402A6]
        r9 = Read<uintptr_t>(mb + 0xA4CA1E4);             //mov r9, [0x000000000780A3E7]
        rax -= rbx;             //sub rax, rbx
        rcx = 0x168B437727824717;               //mov rcx, 0x168B437727824717
        rax *= rcx;             //imul rax, rcx
        rcx = 0x45308B9197D0FD0C;               //mov rcx, 0x45308B9197D0FD0C
        rax += rcx;             //add rax, rcx
        rax += rbx;             //add rax, rbx
        rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
        rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
        rcx ^= r9;              //xor rcx, r9
        rcx = ~rcx;             //not rcx
        rax *= Read<uintptr_t>(rcx + 0x13);               //imul rax, [rcx+0x13]
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x15;           //shr rcx, 0x15
        rax ^= rcx;             //xor rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x2A;           //shr rcx, 0x2A
        rcx ^= r10;             //xor rcx, r10
        rax ^= rcx;             //xor rax, rcx
        rcx = 0x106DBB44164D7574;               //mov rcx, 0x106DBB44164D7574
        rax ^= rcx;             //xor rax, rcx
        return rax;
    }
    case 7:
    {
        r15 = mb + 0x654;               //lea r15, [0xFFFFFFFFFD340416]
        r11 = Read<uintptr_t>(mb + 0xA4CA1E4);            //mov r11, [0x0000000007809EF8]
        rcx = 0x4B726662F15631D3;               //mov rcx, 0x4B726662F15631D3
        rax += rcx;             //add rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x25;           //shr rcx, 0x25
        rax ^= rcx;             //xor rax, rcx
        rcx = 0xC19C0C0BD182C55F;               //mov rcx, 0xC19C0C0BD182C55F
        rax *= rcx;             //imul rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x1C;           //shr rcx, 0x1C
        rax ^= rcx;             //xor rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x38;           //shr rcx, 0x38
        rax ^= rcx;             //xor rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x13;           //shr rcx, 0x13
        rax ^= rcx;             //xor rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x26;           //shr rcx, 0x26
        rax ^= rcx;             //xor rax, rcx
        rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
        rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
        rcx ^= r11;             //xor rcx, r11
        rcx = ~rcx;             //not rcx
        rax *= Read<uintptr_t>(rcx + 0x13);               //imul rax, [rcx+0x13]
        rcx = r10;              //mov rcx, r10
        rcx ^= r15;             //xor rcx, r15
        rax -= rcx;             //sub rax, rcx
        rcx = 0x365856E75B6B102E;               //mov rcx, 0x365856E75B6B102E
        rax ^= rcx;             //xor rax, rcx
        return rax;
    }
    case 8:
    {
        rbx = mb;               //lea rbx, [0xFFFFFFFFFD33F84C]
        r11 = Read<uintptr_t>(mb + 0xA4CA1E4);            //mov r11, [0x00000000078099CA]
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x26;           //shr rcx, 0x26
        rax ^= rcx;             //xor rax, rcx
        rdx = 0;                //and rdx, 0xFFFFFFFFC0000000
        rdx = _rotl64(rdx, 0x10);               //rol rdx, 0x10
        rdx ^= r11;             //xor rdx, r11
        rdx = ~rdx;             //not rdx
        rax *= Read<uintptr_t>(rdx + 0x13);               //imul rax, [rdx+0x13]
        rdx = mb + 0x60E4CDB9;          //lea rdx, [0x000000005E18C21E]
        rcx = r10;              //mov rcx, r10
        rcx *= rdx;             //imul rcx, rdx
        rcx -= rbx;             //sub rcx, rbx
        rax += rcx;             //add rax, rcx
        rax ^= r10;             //xor rax, r10
        rcx = 0x103F869F108D72E7;               //mov rcx, 0x103F869F108D72E7
        rax *= rcx;             //imul rax, rcx
        rcx = 0xF8293C9CC997C23B;               //mov rcx, 0xF8293C9CC997C23B
        rax ^= rcx;             //xor rax, rcx
        rcx = 0x237485300E1BA9B4;               //mov rcx, 0x237485300E1BA9B4
        rax += rcx;             //add rax, rcx
        return rax;
    }
    case 9:
    {
        rbx = mb;               //lea rbx, [0xFFFFFFFFFD33F412]
        r13 = mb + 0x294BAA8A;          //lea r13, [0x00000000267F9E8D]
        r12 = mb + 0x524F4E33;          //lea r12, [0x000000004F834227]
        r9 = Read<uintptr_t>(mb + 0xA4CA1E4);             //mov r9, [0x000000000780952A]
        rcx = r12;              //mov rcx, r12
        rcx = ~rcx;             //not rcx
        rcx += r10;             //add rcx, r10
        rax += rcx;             //add rax, rcx
        rax += rbx;             //add rax, rbx
        rcx = rbx + 0xef67;             //lea rcx, [rbx+0xEF67]
        rcx += r10;             //add rcx, r10
        rax ^= rcx;             //xor rax, rcx
        rcx = 0xE634D55B1A06EEB9;               //mov rcx, 0xE634D55B1A06EEB9
        rax *= rcx;             //imul rax, rcx
        rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
        rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
        rcx ^= r9;              //xor rcx, r9
        rcx = ~rcx;             //not rcx
        rax *= Read<uintptr_t>(rcx + 0x13);               //imul rax, [rcx+0x13]
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x26;           //shr rcx, 0x26
        rax ^= rcx;             //xor rax, rcx
        rcx = r10;              //mov rcx, r10
        rcx = ~rcx;             //not rcx
        rcx *= r13;             //imul rcx, r13
        rax ^= rcx;             //xor rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0xF;            //shr rcx, 0x0F
        rax ^= rcx;             //xor rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x1E;           //shr rcx, 0x1E
        rax ^= rcx;             //xor rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x3C;           //shr rcx, 0x3C
        rax ^= rcx;             //xor rax, rcx
        return rax;
    }
    case 10:
    {
        rbx = mb;               //lea rbx, [0xFFFFFFFFFD33ED4E]
        r12 = mb + 0x3AB5494F;          //lea r12, [0x0000000037E9368E]
        r15 = mb + 0x2BA88ECC;          //lea r15, [0x0000000028DC7BFC]
        r11 = Read<uintptr_t>(mb + 0xA4CA1E4);            //mov r11, [0x0000000007808E8C]
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x5;            //shr rcx, 0x05
        rax ^= rcx;             //xor rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0xA;            //shr rcx, 0x0A
        rax ^= rcx;             //xor rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x14;           //shr rcx, 0x14
        rax ^= rcx;             //xor rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x28;           //shr rcx, 0x28
        rax ^= rcx;             //xor rax, rcx
        rcx = r12;              //mov rcx, r12
        rcx = ~rcx;             //not rcx
        rcx *= r10;             //imul rcx, r10
        rax += rcx;             //add rax, rcx
        rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
        rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
        rcx ^= r11;             //xor rcx, r11
        rcx = ~rcx;             //not rcx
        rax *= Read<uintptr_t>(rcx + 0x13);               //imul rax, [rcx+0x13]
        rcx = r10;              //mov rcx, r10
        rcx *= r15;             //imul rcx, r15
        rax ^= rcx;             //xor rax, rcx
        rcx = 0xB0032DEADD62D54C;               //mov rcx, 0xB0032DEADD62D54C
        rax += rcx;             //add rax, rcx
        rax += rbx;             //add rax, rbx
        rcx = 0x94972D923648A93D;               //mov rcx, 0x94972D923648A93D
        rax *= rcx;             //imul rax, rcx
        return rax;
    }
    case 11:
    {
        rbx = mb;               //lea rbx, [0xFFFFFFFFFD33E820]
        r11 = Read<uintptr_t>(mb + 0xA4CA1E4);            //mov r11, [0x00000000078089A5]
        rcx = r10;              //mov rcx, r10
        rcx = ~rcx;             //not rcx
        rcx -= rbx;             //sub rcx, rbx
        rcx -= 0x8735;          //sub rcx, 0x8735
        rax ^= rcx;             //xor rax, rcx
        uintptr_t RSP_0x48;
        RSP_0x48 = 0x4A4BD6BF0A661C25;          //mov rcx, 0x4A4BD6BF0A661C25 : RSP+0x48
        rax *= RSP_0x48;                //imul rax, [rsp+0x48]
        uintptr_t RSP_0xFFFFFFFFFFFFFF98;
        RSP_0xFFFFFFFFFFFFFF98 = 0x63F84D36C7104CA2;            //mov rcx, 0x63F84D36C7104CA2 : RBP+0xFFFFFFFFFFFFFF98
        rax += RSP_0xFFFFFFFFFFFFFF98;          //add rax, [rbp-0x68]
        rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
        rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
        rcx ^= r11;             //xor rcx, r11
        rcx = ~rcx;             //not rcx
        rax *= Read<uintptr_t>(rcx + 0x13);               //imul rax, [rcx+0x13]
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x9;            //shr rcx, 0x09
        rax ^= rcx;             //xor rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x12;           //shr rcx, 0x12
        rax ^= rcx;             //xor rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x24;           //shr rcx, 0x24
        rax ^= rcx;             //xor rax, rcx
        rcx = mb + 0xF43B;              //lea rcx, [0xFFFFFFFFFD34DA87]
        rax -= rcx;             //sub rax, rcx
        rax += r10;             //add rax, r10
        rcx = 0x25F4D7E70862F64;                //mov rcx, 0x25F4D7E70862F64
        rcx -= r10;             //sub rcx, r10
        rax += rcx;             //add rax, rcx
        return rax;
    }
    case 12:
    {
        r14 = mb + 0x5C6EDFEB;          //lea r14, [0x0000000059A2C347]
        r11 = Read<uintptr_t>(mb + 0xA4CA1E4);            //mov r11, [0x00000000078084E3]
        rcx = 0x60E7602E2CBBF58F;               //mov rcx, 0x60E7602E2CBBF58F
        rax *= rcx;             //imul rax, rcx
        rax -= r10;             //sub rax, r10
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x13;           //shr rcx, 0x13
        rax ^= rcx;             //xor rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x26;           //shr rcx, 0x26
        rax ^= rcx;             //xor rax, rcx
        rcx = 0x5BECE811E5282A13;               //mov rcx, 0x5BECE811E5282A13
        rax *= rcx;             //imul rax, rcx
        rax ^= r10;             //xor rax, r10
        rax ^= r14;             //xor rax, r14
        rcx = 0x36AAED9D7BDACA91;               //mov rcx, 0x36AAED9D7BDACA91
        rax -= rcx;             //sub rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x4;            //shr rcx, 0x04
        rax ^= rcx;             //xor rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x8;            //shr rcx, 0x08
        rax ^= rcx;             //xor rax, rcx
        rcx = rax;              //mov rcx, rax
        rdx = 0;                //and rdx, 0xFFFFFFFFC0000000
        rcx >>= 0x10;           //shr rcx, 0x10
        rax ^= rcx;             //xor rax, rcx
        rdx = _rotl64(rdx, 0x10);               //rol rdx, 0x10
        rcx = rax;              //mov rcx, rax
        rdx ^= r11;             //xor rdx, r11
        rcx >>= 0x20;           //shr rcx, 0x20
        rdx = ~rdx;             //not rdx
        rax ^= rcx;             //xor rax, rcx
        rax *= Read<uintptr_t>(rdx + 0x13);               //imul rax, [rdx+0x13]
        return rax;
    }
    case 13:
    {
        rbx = mb;               //lea rbx, [0xFFFFFFFFFD33DE21]
        r9 = Read<uintptr_t>(mb + 0xA4CA1E4);             //mov r9, [0x0000000007807F4B]
        rcx = 0x2682F4D689B5671D;               //mov rcx, 0x2682F4D689B5671D
        rax *= rcx;             //imul rax, rcx
        rcx = mb + 0x5C70;              //lea rcx, [0xFFFFFFFFFD3437BE]
        rax -= r10;             //sub rax, r10
        rax += rcx;             //add rax, rcx
        rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
        rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
        rcx ^= r9;              //xor rcx, r9
        rcx = ~rcx;             //not rcx
        rax *= Read<uintptr_t>(rcx + 0x13);               //imul rax, [rcx+0x13]
        rax -= r10;             //sub rax, r10
        rax -= rbx;             //sub rax, rbx
        rcx = 0xC9C580B162511036;               //mov rcx, 0xC9C580B162511036
        rax ^= rcx;             //xor rax, rcx
        rax += r10;             //add rax, r10
        rcx = rax;              //mov rcx, rax
        rcx >>= 0xB;            //shr rcx, 0x0B
        rax ^= rcx;             //xor rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x16;           //shr rcx, 0x16
        rax ^= rcx;             //xor rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x2C;           //shr rcx, 0x2C
        rax ^= rcx;             //xor rax, rcx
        return rax;
    }
    case 14:
    {
        rbx = mb;               //lea rbx, [0xFFFFFFFFFD33D8B2]
        r11 = Read<uintptr_t>(mb + 0xA4CA1E4);            //mov r11, [0x0000000007807A38]
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x3;            //shr rcx, 0x03
        rax ^= rcx;             //xor rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x6;            //shr rcx, 0x06
        rax ^= rcx;             //xor rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0xC;            //shr rcx, 0x0C
        rax ^= rcx;             //xor rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x18;           //shr rcx, 0x18
        rax ^= rcx;             //xor rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x30;           //shr rcx, 0x30
        rax ^= rcx;             //xor rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x1E;           //shr rcx, 0x1E
        rax ^= rcx;             //xor rax, rcx
        rdx = 0;                //and rdx, 0xFFFFFFFFC0000000
        rcx = rax;              //mov rcx, rax
        rdx = _rotl64(rdx, 0x10);               //rol rdx, 0x10
        rcx >>= 0x3C;           //shr rcx, 0x3C
        rdx ^= r11;             //xor rdx, r11
        rax ^= rcx;             //xor rax, rcx
        rdx = ~rdx;             //not rdx
        rax -= rbx;             //sub rax, rbx
        rax *= Read<uintptr_t>(rdx + 0x13);               //imul rax, [rdx+0x13]
        rcx = 0x78B39385B5F074F2;               //mov rcx, 0x78B39385B5F074F2
        rax ^= rcx;             //xor rax, rcx
        rax -= r10;             //sub rax, r10
        rcx = 0x3849D20FD1391A9C;               //mov rcx, 0x3849D20FD1391A9C
        rax ^= rcx;             //xor rax, rcx
        rcx = 0xC00D39A041991E8D;               //mov rcx, 0xC00D39A041991E8D
        rax *= rcx;             //imul rax, rcx
        return rax;
    }
    case 15:
    {
        rbx = mb;               //lea rbx, [0xFFFFFFFFFD33D39D]
        r15 = mb + 0x2C05B53A;          //lea r15, [0x00000000293988C8]
        r9 = Read<uintptr_t>(mb + 0xA4CA1E4);             //mov r9, [0x00000000078074E9]
        rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
        rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
        rcx ^= r9;              //xor rcx, r9
        rcx = ~rcx;             //not rcx
        rax *= Read<uintptr_t>(rcx + 0x13);               //imul rax, [rcx+0x13]
        rax -= r10;             //sub rax, r10
        rax -= rbx;             //sub rax, rbx
        rcx = r10;              //mov rcx, r10
        rcx = ~rcx;             //not rcx
        rcx ^= r15;             //xor rcx, r15
        rax -= rcx;             //sub rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0xD;            //shr rcx, 0x0D
        rax ^= rcx;             //xor rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x1A;           //shr rcx, 0x1A
        rax ^= rcx;             //xor rax, rcx
        rcx = rax;              //mov rcx, rax
        rcx >>= 0x34;           //shr rcx, 0x34
        rax ^= rcx;             //xor rax, rcx
        rcx = 0x6C177C995AED1613;               //mov rcx, 0x6C177C995AED1613
        rax *= rcx;             //imul rax, rcx
        rcx = 0xC5F26860B9637B27;               //mov rcx, 0xC5F26860B9637B27
        rax ^= rcx;             //xor rax, rcx
        rcx = 0x563DC016F252B280;               //mov rcx, 0x563DC016F252B280
        rax += rcx;             //add rax, rcx
        return rax;
    }
    }
}
uintptr_t get_bone_index(uint32_t bone_index, QWORD BaseAddress, QWORD Peb)
{
    auto mb = BaseAddress;
    uint64_t rax = mb, rbx = mb, rcx = mb, rdx = mb, rdi = mb, rsi = mb, r8 = mb, r9 = mb, r10 = mb, r11 = mb, r12 = mb, r13 = mb, r14 = mb, r15 = mb;
    rdi = bone_index;
    rcx = rdi * 0x13C8;
    rax = 0x47B14E60F79042A7;               //mov rax, 0x47B14E60F79042A7
    rax = _umul128(rax, rcx, (uintptr_t*)&rdx);             //mul rcx
    r11 = mb;               //lea r11, [0xFFFFFFFFFD4974B8]
    r10 = 0x9C9EEA3E2C95BCEF;               //mov r10, 0x9C9EEA3E2C95BCEF
    rdx >>= 0xB;            //shr rdx, 0x0B
    rax = rdx * 0x1C91;             //imul rax, rdx, 0x1C91
    rcx -= rax;             //sub rcx, rax
    rax = 0x27856C2E77E032A3;               //mov rax, 0x27856C2E77E032A3
    r8 = rcx * 0x1C91;              //imul r8, rcx, 0x1C91
    rax = _umul128(rax, r8, (uintptr_t*)&rdx);              //mul r8
    rdx >>= 0xB;            //shr rdx, 0x0B
    rax = rdx * 0x33D2;             //imul rax, rdx, 0x33D2
    r8 -= rax;              //sub r8, rax
    rax = 0xE76C3265CFF9AC0B;               //mov rax, 0xE76C3265CFF9AC0B
    rax = _umul128(rax, r8, (uintptr_t*)&rdx);              //mul r8
    rax = 0xCCCCCCCCCCCCCCCD;               //mov rax, 0xCCCCCCCCCCCCCCCD
    rdx >>= 0xC;            //shr rdx, 0x0C
    rcx = rdx * 0x11B3;             //imul rcx, rdx, 0x11B3
    rax = _umul128(rax, r8, (uintptr_t*)&rdx);              //mul r8
    rdx >>= 0x2;            //shr rdx, 0x02
    rcx += rdx;             //add rcx, rdx
    rax = rcx + rcx * 4;            //lea rax, [rcx+rcx*4]
    rax += rax;             //add rax, rax
    rcx = r8 + r8 * 2;              //lea rcx, [r8+r8*2]
    rcx <<= 0x2;            //shl rcx, 0x02
    rcx -= rax;             //sub rcx, rax
    rax = *(uint16_t*)(rcx + r11 * 1 + 0xA59EF50);          //movzx eax, word ptr [rcx+r11*1+0xA59EF50]
    r8 = rax * 0x13C8;              //imul r8, rax, 0x13C8
    rax = r10;              //mov rax, r10
    rax = _umul128(rax, r8, (uintptr_t*)&rdx);              //mul r8
    rax = r10;              //mov rax, r10
    rdx >>= 0xC;            //shr rdx, 0x0C
    rcx = rdx * 0x1A27;             //imul rcx, rdx, 0x1A27
    r8 -= rcx;              //sub r8, rcx
    r9 = r8 * 0x1C3B;               //imul r9, r8, 0x1C3B
    rax = _umul128(rax, r9, (uintptr_t*)&rdx);              //mul r9
    rdx >>= 0xC;            //shr rdx, 0x0C
    rax = rdx * 0x1A27;             //imul rax, rdx, 0x1A27
    r9 -= rax;              //sub r9, rax
    rax = 0x27DFA38A1CE4D6F9;               //mov rax, 0x27DFA38A1CE4D6F9
    rax = _umul128(rax, r9, (uintptr_t*)&rdx);              //mul r9
    rax = r9;               //mov rax, r9
    rax -= rdx;             //sub rax, rdx
    rax >>= 0x1;            //shr rax, 0x01
    rax += rdx;             //add rax, rdx
    rax >>= 0x9;            //shr rax, 0x09
    rcx = rax * 0x376;              //imul rcx, rax, 0x376
    rax = 0x2E8BA2E8BA2E8BA3;               //mov rax, 0x2E8BA2E8BA2E8BA3
    rax = _umul128(rax, r9, (uintptr_t*)&rdx);              //mul r9
    rdx >>= 0x1;            //shr rdx, 0x01
    rcx += rdx;             //add rcx, rdx
    rax = rcx * 0x16;               //imul rax, rcx, 0x16
    rcx = r9 + r9 * 2;              //lea rcx, [r9+r9*2]
    rcx <<= 0x3;            //shl rcx, 0x03
    rcx -= rax;             //sub rcx, rax
    r15 = *(uint16_t*)(rcx + r11 * 1 + 0xA5AA050);          //movsx r15d, word ptr [rcx+r11*1+0xA5AA050]
    return r15;
}