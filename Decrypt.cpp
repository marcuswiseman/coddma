#include <cstdint>
#include "Driver.h"

uintptr_t decrypt_client_info(const Driver& driver)
{
    const uint64_t mb = driver.base_addr;
    uint64_t rax = mb, rbx = mb, rcx = mb, rdx = mb, rdi = mb, rsi = mb, r8 = mb, r9 = mb, r10 = mb, r11 = mb, r12 = mb, r13 = mb, r14 = mb, r15 = mb;
    ;
    if (!none)
        return none;
    rdx = driver.target_peb;                //mov rdx, gs:[rax]
    //failed to translate: jnz 0x00000000000001DD
    return none;
}

uintptr_t decrypt_client_base(const Driver& driver, uintptr_t client_info)
{
    const uint64_t mb = driver.base_addr;
    uint64_t rax = mb, rbx = mb, rcx = mb, rdx = mb, rdi = mb, rsi = mb, r8 = mb, r9 = mb, r10 = mb, r11 = mb, r12 = mb, r13 = mb, r14 = mb, r15 = mb;
    r8 = driver.Read<uintptr_t>(client_info + 0x18ccb0);
    if (!r8)
        return r8;
    r9 = ~driver.target_peb;                 //mov r9, gs:[rax]
    rax = r9;               //mov rax, r9
    rax = _rotl64(rax, 0x21);               //rol rax, 0x21
    rax &= 0xF;
    switch (rax) {
    case 0:
    {
        rax = 0x9141C45BFD5B39F7;               //mov rax, 0x9141C45BFD5B39F7
        r8 ^= rax;              //xor r8, rax
        return r8;
    }
    case 1:
    {
        return r8;
    }
    case 2:
    {
        rdx = driver.Read<uintptr_t>(driver.base_addr + 0xAB6E10E);             //mov rdx, [0x00000000082C1C66]
        rax = 0x8ADB88DACDCF2087;               //mov rax, 0x8ADB88DACDCF2087
        r8 *= rax;              //imul r8, rax
        rax = 0x7962CBE13BD24CEA;               //mov rax, 0x7962CBE13BD24CEA
        r8 += rax;              //add r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x10;           //shr rax, 0x10
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x20;           //shr rax, 0x20
        r8 ^= rax;              //xor r8, rax
        r8 += r9;               //add r8, r9
        r8 += r9;               //add r8, r9
        rax = 0;                //and rax, 0xFFFFFFFFC0000000
        rax = _rotl64(rax, 0x10);               //rol rax, 0x10
        rax ^= rdx;             //xor rax, rdx
        rax = ~rax;             //not rax
        r8 *= driver.Read<uintptr_t>(rax + 0x19);               //imul r8, [rax+0x19]
        r8 -= r9;               //sub r8, r9
        rax = r8;               //mov rax, r8
        rax >>= 0x1D;           //shr rax, 0x1D
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x3A;           //shr rax, 0x3A
        r8 ^= rax;              //xor r8, rax
        return r8;
    }
    case 3:
    {
        return r8;
    }
    case 4:
    {
        return r8;
    }
    case 5:
    {
        return r8;
    }
    case 6:
    {
        rcx = driver.Read<uintptr_t>(driver.base_addr + 0xAB6E10E);             //mov rcx, [0x00000000082C092B]
        rax = r8;               //mov rax, r8
        rax >>= 0xF;            //shr rax, 0x0F
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x1E;           //shr rax, 0x1E
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x3C;           //shr rax, 0x3C
        r8 ^= rax;              //xor r8, rax
        r8 -= r9;               //sub r8, r9
        r8 ^= r9;               //xor r8, r9
        rax = 0;                //and rax, 0xFFFFFFFFC0000000
        rax = _rotl64(rax, 0x10);               //rol rax, 0x10
        rax ^= rcx;             //xor rax, rcx
        rax = ~rax;             //not rax
        rax = driver.Read<uintptr_t>(rax + 0x19);               //mov rax, [rax+0x19]
        ;               //imul rax, [rsp+0x398] -- didn't find trace -> use base
        r8 *= rax;              //imul r8, rax
        rax = driver.base_addr;                 //lea rax, [0xFFFFFFFFFD7527B9]
        r8 -= rax;              //sub r8, rax
        rax = 0xA1839DE961442277;               //mov rax, 0xA1839DE961442277
        r8 *= rax;              //imul r8, rax
        return r8;
    }
    case 7:
    {
        r15 = driver.base_addr + 0x7E9B;                //lea r15, [0xFFFFFFFFFD75A268]
        r8 += r15;              //add r8, r15
        rcx = r9;               //mov rcx, r9
        rcx = ~rcx;             //not rcx
        r8 += rcx;              //add r8, rcx
        rax = r8;               //mov rax, r8
        rax >>= 0xD;            //shr rax, 0x0D
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x1A;           //shr rax, 0x1A
        r8 ^= rax;              //xor r8, rax
        return r8;
    }
    case 8:
    {
        r13 = driver.base_addr;                 //lea r13, [0xFFFFFFFFFD751EE7]
        rcx = driver.Read<uintptr_t>(driver.base_addr + 0xAB6E10E);             //mov rcx, [0x00000000082BFFD4]
        rax = 0xF27764D7BCC134E1;               //mov rax, 0xF27764D7BCC134E1
        r8 *= rax;              //imul r8, rax
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
        r8 ^= r13;              //xor r8, r13
        rax = 0xC3107C6F6CB6AAB7;               //mov rax, 0xC3107C6F6CB6AAB7
        r8 *= rax;              //imul r8, rax
        rax = 0xD1B5E7C8461A7E03;               //mov rax, 0xD1B5E7C8461A7E03
        r8 ^= rax;              //xor r8, rax
        rax = driver.base_addr + 0x4977696C;            //lea rax, [0x0000000046EC869E]
        rax = ~rax;             //not rax
        rax += r9;              //add rax, r9
        r8 += rax;              //add r8, rax
        rax = r9;               //mov rax, r9
        rax -= r13;             //sub rax, r13
        rax += 0xFFFFFFFFFFFF4E09;              //add rax, 0xFFFFFFFFFFFF4E09
        r8 += rax;              //add r8, rax
        rax = 0;                //and rax, 0xFFFFFFFFC0000000
        rax = _rotl64(rax, 0x10);               //rol rax, 0x10
        rax ^= rcx;             //xor rax, rcx
        rax = ~rax;             //not rax
        r8 *= driver.Read<uintptr_t>(rax + 0x19);               //imul r8, [rax+0x19]
        return r8;
    }
    case 9:
    {
        rax = r8;               //mov rax, r8
        rax >>= 0x23;           //shr rax, 0x23
        r8 ^= rax;              //xor r8, rax
        rax = 0xA7B0F0AA378850A7;               //mov rax, 0xA7B0F0AA378850A7
        r8 *= rax;              //imul r8, rax
        rax = driver.base_addr;                 //lea rax, [0xFFFFFFFFFD751797]
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x1B;           //shr rax, 0x1B
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x36;           //shr rax, 0x36
        r8 ^= rax;              //xor r8, rax
        rax = driver.base_addr;                 //lea rax, [0xFFFFFFFFFD7516CE]
        rax += 0xD85;           //add rax, 0xD85
        rax += r9;              //add rax, r9
        r8 += rax;              //add r8, rax
        return r8;
    }
    case 10:
    {
        rsi = driver.base_addr + 0xF084;                //lea rsi, [0xFFFFFFFFFD760608]
        rcx = driver.Read<uintptr_t>(driver.base_addr + 0xAB6E10E);             //mov rcx, [0x00000000082BF674]
        rax = 0x98CD10A39FEEABC3;               //mov rax, 0x98CD10A39FEEABC3
        r8 *= rax;              //imul r8, rax
        rax = driver.base_addr;                 //lea rax, [0xFFFFFFFFFD75142F]
        rax += 0x8AF0;          //add rax, 0x8AF0
        rax += r9;              //add rax, r9
        r8 += rax;              //add r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x10;           //shr rax, 0x10
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x20;           //shr rax, 0x20
        r8 ^= rax;              //xor r8, rax
        rax = r9;               //mov rax, r9
        rax = ~rax;             //not rax
        rax ^= rsi;             //xor rax, rsi
        r8 += rax;              //add r8, rax
        rax = 0xDF8A1660CBF5F30F;               //mov rax, 0xDF8A1660CBF5F30F
        r8 *= rax;              //imul r8, rax
        rax = 0xA829D63D19635A8D;               //mov rax, 0xA829D63D19635A8D
        r8 ^= rax;              //xor r8, rax
        rax = 0;                //and rax, 0xFFFFFFFFC0000000
        rax = _rotl64(rax, 0x10);               //rol rax, 0x10
        rax ^= rcx;             //xor rax, rcx
        rax = ~rax;             //not rax
        r8 *= driver.Read<uintptr_t>(rax + 0x19);               //imul r8, [rax+0x19]
        r8 ^= r9;               //xor r8, r9
        return r8;
    }
    case 11:
    {
        return r8;
    }
    case 12:
    {
        rsi = driver.base_addr + 0x4291859E;            //lea rsi, [0x00000000400692BC]
        rax = driver.base_addr;                 //lea rax, [0xFFFFFFFFFD750A5B]
        r8 -= rax;              //sub r8, rax
        rax = rsi;              //mov rax, rsi
        rax = ~rax;             //not rax
        rax ^= r9;              //xor rax, r9
        r8 ^= rax;              //xor r8, rax
        return r8;
    }
    case 13:
    {
        return r8;
    }
    case 14:
    {
        return r8;
    }
    case 15:
    {
        rbx = driver.base_addr + 0x56C36699;            //lea rbx, [0x00000000543864C4]
        rdx = driver.Read<uintptr_t>(driver.base_addr + 0xAB6E10E);             //mov rdx, [0x00000000082BDF0F]
        rax = 0x14288A7031FA1D2A;               //mov rax, 0x14288A7031FA1D2A
        r8 += rax;              //add r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0xA;            //shr rax, 0x0A
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x14;           //shr rax, 0x14
        r8 ^= rax;              //xor r8, rax
        rax = r8;               //mov rax, r8
        rax >>= 0x28;           //shr rax, 0x28
        r8 ^= rax;              //xor r8, rax
        rax = 0xF471F0FE111CB275;               //mov rax, 0xF471F0FE111CB275
        r8 *= rax;              //imul r8, rax
        rax = rbx;              //mov rax, rbx
        rax = ~rax;             //not rax
        rax *= r9;              //imul rax, r9
        r8 ^= rax;              //xor r8, rax
        rax = driver.base_addr;                 //lea rax, [0xFFFFFFFFFD74FCE2]
        r8 -= r9;               //sub r8, r9
        r8 -= rax;              //sub r8, rax
        r8 -= 0x57EC1422;               //sub r8, 0x57EC1422
        rax = r9;               //mov rax, r9
        ;               //imul rax, [rsp+0xB8] -- didn't find trace -> use base
        r8 += rax;              //add r8, rax
        rax = 0;                //and rax, 0xFFFFFFFFC0000000
        rax = _rotl64(rax, 0x10);               //rol rax, 0x10
        rax ^= rdx;             //xor rax, rdx
        rax = ~rax;             //not rax
        r8 *= driver.Read<uintptr_t>(rax + 0x19);               //imul r8, [rax+0x19]
        return r8;
    }
    }
}
uintptr_t decrypt_bone_base(const Driver& driver)
{
    const uint64_t mb = driver.base_addr;
    uint64_t rax = mb, rbx = mb, rcx = mb, rdx = mb, rdi = mb, rsi = mb, r8 = mb, r9 = mb, r10 = mb, r11 = mb, r12 = mb, r13 = mb, r14 = mb, r15 = mb;
    rdx = driver.Read<uintptr_t>(driver.base_addr + 0xE12C988);
    if (!rdx)
        return rdx;
    r11 = driver.target_peb;                //mov r11, gs:[rax]
    rax = r11;              //mov rax, r11
    rax = _rotr64(rax, 0x15);               //ror rax, 0x15
    rax &= 0xF;
    switch (rax) {
    case 0:
    {
        r13 = driver.base_addr + 0x629DAB46;            //lea r13, [0x000000006034D31E]
        r9 = driver.Read<uintptr_t>(driver.base_addr + 0xAB6E1FC);              //mov r9, [0x00000000084E0915]
        rax = 0xAC145E023332D189;               //mov rax, 0xAC145E023332D189
        rdx ^= rax;             //xor rdx, rax
        rax = r13;              //mov rax, r13
        rax = ~rax;             //not rax
        rax *= r11;             //imul rax, r11
        rdx += rax;             //add rdx, rax
        rax = 0xFDEBD2F07B05670D;               //mov rax, 0xFDEBD2F07B05670D
        rdx *= rax;             //imul rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x3;            //shr rax, 0x03
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x6;            //shr rax, 0x06
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0xC;            //shr rax, 0x0C
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x18;           //shr rax, 0x18
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x30;           //shr rax, 0x30
        rdx ^= rax;             //xor rdx, rax
        rax = 0xF0805972B46E082;                //mov rax, 0xF0805972B46E082
        rdx -= rax;             //sub rdx, rax
        rax = r11;              //mov rax, r11
        uintptr_t RSP_0x50;
        RSP_0x50 = driver.base_addr + 0x9895;           //lea rax, [0xFFFFFFFFFD97C07C] : RSP+0x50
        rax ^= RSP_0x50;                //xor rax, [rsp+0x50]
        rdx += rax;             //add rdx, rax
        rax = 0;                //and rax, 0xFFFFFFFFC0000000
        rax = _rotl64(rax, 0x10);               //rol rax, 0x10
        rax ^= r9;              //xor rax, r9
        rax = _byteswap_uint64(rax);            //bswap rax
        rdx *= driver.Read<uintptr_t>(rax + 0x11);              //imul rdx, [rax+0x11]
        rax = rdx;              //mov rax, rdx
        rax >>= 0x4;            //shr rax, 0x04
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x8;            //shr rax, 0x08
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x10;           //shr rax, 0x10
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x20;           //shr rax, 0x20
        rdx ^= rax;             //xor rdx, rax
        return rdx;
    }
    case 1:
    {
        r9 = driver.Read<uintptr_t>(driver.base_addr + 0xAB6E1FC);              //mov r9, [0x00000000084E0273]
        rax = 0;                //and rax, 0xFFFFFFFFC0000000
        rax = _rotl64(rax, 0x10);               //rol rax, 0x10
        rax ^= r9;              //xor rax, r9
        rax = _byteswap_uint64(rax);            //bswap rax
        rdx *= driver.Read<uintptr_t>(rax + 0x11);              //imul rdx, [rax+0x11]
        rax = 0x3ECBF33498144A56;               //mov rax, 0x3ECBF33498144A56
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0xA;            //shr rax, 0x0A
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x14;           //shr rax, 0x14
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x28;           //shr rax, 0x28
        rdx ^= rax;             //xor rdx, rax
        rax = 0x87F19886B363B05B;               //mov rax, 0x87F19886B363B05B
        rdx *= rax;             //imul rdx, rax
        rdx -= r11;             //sub rdx, r11
        rax = 0x6303659E1F345AFF;               //mov rax, 0x6303659E1F345AFF
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x15;           //shr rax, 0x15
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x2A;           //shr rax, 0x2A
        rdx ^= rax;             //xor rdx, rax
        rdx += r11;             //add rdx, r11
        return rdx;
    }
    case 2:
    {
        r13 = driver.base_addr + 0x6F7AC17A;            //lea r13, [0x000000006D11DD94]
        rcx = driver.Read<uintptr_t>(driver.base_addr + 0xAB6E1FC);             //mov rcx, [0x00000000084DFD7D]
        rdx += r11;             //add rdx, r11
        rax = rdx;              //mov rax, rdx
        rax >>= 0x13;           //shr rax, 0x13
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x26;           //shr rax, 0x26
        rdx ^= rax;             //xor rdx, rax
        rdx -= r11;             //sub rdx, r11
        rax = driver.base_addr + 0x62BA;                //lea rax, [0xFFFFFFFFFD977B82]
        rdx += rax;             //add rdx, rax
        rax = 0x6367F6E201B667AF;               //mov rax, 0x6367F6E201B667AF
        rdx *= rax;             //imul rdx, rax
        rax = 0x7EA109C91958478C;               //mov rax, 0x7EA109C91958478C
        rdx -= rax;             //sub rdx, rax
        rdx ^= r11;             //xor rdx, r11
        rdx ^= r13;             //xor rdx, r13
        rax = 0x79658B29969CD86A;               //mov rax, 0x79658B29969CD86A
        rdx -= rax;             //sub rdx, rax
        rax = 0;                //and rax, 0xFFFFFFFFC0000000
        rax = _rotl64(rax, 0x10);               //rol rax, 0x10
        rax ^= rcx;             //xor rax, rcx
        rax = _byteswap_uint64(rax);            //bswap rax
        rdx *= driver.Read<uintptr_t>(rax + 0x11);              //imul rdx, [rax+0x11]
        return rdx;
    }
    case 3:
    {
        r14 = driver.base_addr + 0xF8CE;                //lea r14, [0xFFFFFFFFFD980FE0]
        r9 = driver.Read<uintptr_t>(driver.base_addr + 0xAB6E1FC);              //mov r9, [0x00000000084DF87E]
        rax = rdx;              //mov rax, rdx
        rax >>= 0x20;           //shr rax, 0x20
        rdx ^= rax;             //xor rdx, rax
        rax = 0xEA0A19EF431520D;                //mov rax, 0xEA0A19EF431520D
        rdx ^= rax;             //xor rdx, rax
        rax = 0xFFFFFFFF93B5ED93;               //mov rax, 0xFFFFFFFF93B5ED93
        rax -= r11;             //sub rax, r11
        rax -= driver.base_addr;                //sub rax, [rsp+0xA8] -- didn't find trace -> use base
        rdx += rax;             //add rdx, rax
        rax = r11;              //mov rax, r11
        rax *= r14;             //imul rax, r14
        rdx -= rax;             //sub rdx, rax
        rax = 0x39F863E9187B3F65;               //mov rax, 0x39F863E9187B3F65
        rdx *= rax;             //imul rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x1F;           //shr rax, 0x1F
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x3E;           //shr rax, 0x3E
        rdx ^= rax;             //xor rdx, rax
        rax = 0x44AFB2020B72DD38;               //mov rax, 0x44AFB2020B72DD38
        rdx += rax;             //add rdx, rax
        rax = 0;                //and rax, 0xFFFFFFFFC0000000
        rax = _rotl64(rax, 0x10);               //rol rax, 0x10
        rax ^= r9;              //xor rax, r9
        rax = _byteswap_uint64(rax);            //bswap rax
        rdx *= driver.Read<uintptr_t>(rax + 0x11);              //imul rdx, [rax+0x11]
        return rdx;
    }
    case 4:
    {
        r13 = driver.base_addr + 0xD76E;                //lea r13, [0xFFFFFFFFFD97E90E]
        r9 = driver.Read<uintptr_t>(driver.base_addr + 0xAB6E1FC);              //mov r9, [0x00000000084DF303]
        rax = r13;              //mov rax, r13
        rax = ~rax;             //not rax
        rax ^= r11;             //xor rax, r11
        rdx -= rax;             //sub rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x24;           //shr rax, 0x24
        rdx ^= rax;             //xor rdx, rax
        rax = 0x2690031C441C94ED;               //mov rax, 0x2690031C441C94ED
        rdx *= rax;             //imul rdx, rax
        rdx ^= r11;             //xor rdx, r11
        rax = 0xA3A6498F1C56BC17;               //mov rax, 0xA3A6498F1C56BC17
        rdx ^= rax;             //xor rdx, rax
        rdx -= r11;             //sub rdx, r11
        rax = 0;                //and rax, 0xFFFFFFFFC0000000
        rax = _rotl64(rax, 0x10);               //rol rax, 0x10
        rax ^= r9;              //xor rax, r9
        rax = _byteswap_uint64(rax);            //bswap rax
        rdx *= driver.Read<uintptr_t>(rax + 0x11);              //imul rdx, [rax+0x11]
        return rdx;
    }
    case 5:
    {
        r10 = driver.Read<uintptr_t>(driver.base_addr + 0xAB6E1FC);             //mov r10, [0x00000000084DEE4F]
        rax = driver.base_addr;                 //lea rax, [0xFFFFFFFFFD970B02]
        rdx += rax;             //add rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x19;           //shr rax, 0x19
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x32;           //shr rax, 0x32
        rdx ^= rax;             //xor rdx, rax
        rax = 0;                //and rax, 0xFFFFFFFFC0000000
        rax = _rotl64(rax, 0x10);               //rol rax, 0x10
        rax ^= r10;             //xor rax, r10
        rax = _byteswap_uint64(rax);            //bswap rax
        rcx = driver.Read<uintptr_t>(rax + 0x11);               //mov rcx, [rax+0x11]
        rax = r11;              //mov rax, r11
        uintptr_t RSP_0x60;
        RSP_0x60 = driver.base_addr + 0x598F00A5;               //lea rax, [0x0000000057260D19] : RSP+0x60
        rax *= RSP_0x60;                //imul rax, [rsp+0x60]
        rax -= driver.base_addr;                //sub rax, [rsp+0xA8] -- didn't find trace -> use base
        rdx += rax;             //add rdx, rax
        rax = 0xC6D870371839E04D;               //mov rax, 0xC6D870371839E04D
        rdx *= rax;             //imul rdx, rax
        rax = 0x2435BC22D4E2922B;               //mov rax, 0x2435BC22D4E2922B
        rdx -= rax;             //sub rdx, rax
        rdx *= rcx;             //imul rdx, rcx
        rax = 0xBBD9DF3CECEEFE74;               //mov rax, 0xBBD9DF3CECEEFE74
        rdx ^= rax;             //xor rdx, rax
        rax = 0x23B4F504FA125955;               //mov rax, 0x23B4F504FA125955
        rdx *= rax;             //imul rdx, rax
        return rdx;
    }
    case 6:
    {
        r10 = driver.Read<uintptr_t>(driver.base_addr + 0xAB6E1FC);             //mov r10, [0x00000000084DE9A9]
        rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
        rax = r11;              //mov rax, r11
        rax -= driver.base_addr;                //sub rax, [rsp+0xA8] -- didn't find trace -> use base
        rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
        rax += 0xFFFFFFFFA7D1474C;              //add rax, 0xFFFFFFFFA7D1474C
        rcx ^= r10;             //xor rcx, r10
        rdx += rax;             //add rdx, rax
        rcx = _byteswap_uint64(rcx);            //bswap rcx
        rdx *= driver.Read<uintptr_t>(rcx + 0x11);              //imul rdx, [rcx+0x11]
        rax = 0xFFFFFFFFC0CD4EE3;               //mov rax, 0xFFFFFFFFC0CD4EE3
        rax -= r11;             //sub rax, r11
        rax -= driver.base_addr;                //sub rax, [rsp+0xA8] -- didn't find trace -> use base
        rdx += rax;             //add rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x23;           //shr rax, 0x23
        rax ^= rdx;             //xor rax, rdx
        rdx = 0x5A8397EF69EB3410;               //mov rdx, 0x5A8397EF69EB3410
        rax += r11;             //add rax, r11
        rax += rdx;             //add rax, rdx
        rdx = driver.base_addr;                 //lea rdx, [0xFFFFFFFFFD9704E9]
        rdx += rax;             //add rdx, rax
        rax = 0x94B908816CF2DBE1;               //mov rax, 0x94B908816CF2DBE1
        rdx *= rax;             //imul rdx, rax
        return rdx;
    }
    case 7:
    {
        r13 = driver.base_addr + 0x6B60;                //lea r13, [0xFFFFFFFFFD976F12]
        r10 = driver.Read<uintptr_t>(driver.base_addr + 0xAB6E1FC);             //mov r10, [0x00000000084DE511]
        rax = driver.base_addr;                 //lea rax, [0xFFFFFFFFFD970072]
        rax += 0xC77B;          //add rax, 0xC77B
        rax += r11;             //add rax, r11
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x9;            //shr rax, 0x09
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x12;           //shr rax, 0x12
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x24;           //shr rax, 0x24
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x13;           //shr rax, 0x13
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x26;           //shr rax, 0x26
        rdx ^= rax;             //xor rdx, rax
        rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
        rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
        rcx ^= r10;             //xor rcx, r10
        rax = r13;              //mov rax, r13
        rax = ~rax;             //not rax
        rax *= r11;             //imul rax, r11
        rcx = _byteswap_uint64(rcx);            //bswap rcx
        rdx += rax;             //add rdx, rax
        rax = 0x3BAB7EE1C2FB5485;               //mov rax, 0x3BAB7EE1C2FB5485
        rdx *= driver.Read<uintptr_t>(rcx + 0x11);              //imul rdx, [rcx+0x11]
        rdx += rax;             //add rdx, rax
        rax = 0xD64310FF7669DED5;               //mov rax, 0xD64310FF7669DED5
        rdx *= rax;             //imul rdx, rax
        rax = 0xC9A0080E2B52320A;               //mov rax, 0xC9A0080E2B52320A
        rdx ^= rax;             //xor rdx, rax
        return rdx;
    }
    case 8:
    {
        r10 = driver.Read<uintptr_t>(driver.base_addr + 0xAB6E1FC);             //mov r10, [0x00000000084DDEFC]
        rax = r11;              //mov rax, r11
        rax -= driver.base_addr;                //sub rax, [rsp+0xA8] -- didn't find trace -> use base
        rax += 0xFFFFFFFF954B94E9;              //add rax, 0xFFFFFFFF954B94E9
        rdx += rax;             //add rdx, rax
        rax = 0;                //and rax, 0xFFFFFFFFC0000000
        rax = _rotl64(rax, 0x10);               //rol rax, 0x10
        rax ^= r10;             //xor rax, r10
        rax = _byteswap_uint64(rax);            //bswap rax
        rdx *= driver.Read<uintptr_t>(rax + 0x11);              //imul rdx, [rax+0x11]
        rax = rdx;              //mov rax, rdx
        rax >>= 0xE;            //shr rax, 0x0E
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x1C;           //shr rax, 0x1C
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x38;           //shr rax, 0x38
        rdx ^= rax;             //xor rdx, rax
        rax = 0x28853EAC80AAB90;                //mov rax, 0x28853EAC80AAB90
        rdx -= rax;             //sub rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x21;           //shr rax, 0x21
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0xB;            //shr rax, 0x0B
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x16;           //shr rax, 0x16
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x2C;           //shr rax, 0x2C
        rdx ^= rax;             //xor rdx, rax
        rax = 0x9ED615C5A516F48D;               //mov rax, 0x9ED615C5A516F48D
        rdx *= rax;             //imul rdx, rax
        rax = 0x4A5451CFD1051B0F;               //mov rax, 0x4A5451CFD1051B0F
        rdx *= rax;             //imul rdx, rax
        return rdx;
    }
    case 9:
    {
        rcx = driver.base_addr + 0x590B7B0F;            //lea rcx, [0x0000000056A2730E]
        r10 = driver.Read<uintptr_t>(driver.base_addr + 0xAB6E1FC);             //mov r10, [0x00000000084DD955]
        rax = rdx;              //mov rax, rdx
        rax >>= 0x25;           //shr rax, 0x25
        rdx ^= rax;             //xor rdx, rax
        rax = 0;                //and rax, 0xFFFFFFFFC0000000
        rax = _rotl64(rax, 0x10);               //rol rax, 0x10
        rax ^= r10;             //xor rax, r10
        rax = _byteswap_uint64(rax);            //bswap rax
        rdx *= driver.Read<uintptr_t>(rax + 0x11);              //imul rdx, [rax+0x11]
        rax = 0xE41AAE0B4978C7A7;               //mov rax, 0xE41AAE0B4978C7A7
        rdx *= rax;             //imul rdx, rax
        rax = 0x4884ED1EDA36D9B2;               //mov rax, 0x4884ED1EDA36D9B2
        rdx -= rax;             //sub rdx, rax
        rdx ^= r11;             //xor rdx, r11
        rax = driver.base_addr + 0x9F7F;                //lea rax, [0xFFFFFFFFFD979601]
        rdx ^= rax;             //xor rdx, rax
        rax = 0xA5F46429036B04E5;               //mov rax, 0xA5F46429036B04E5
        rdx *= rax;             //imul rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x27;           //shr rax, 0x27
        rdx ^= rax;             //xor rdx, rax
        rdx -= r11;             //sub rdx, r11
        rdx += rcx;             //add rdx, rcx
        return rdx;
    }
    case 10:
    {
        r9 = driver.Read<uintptr_t>(driver.base_addr + 0xAB6E1FC);              //mov r9, [0x00000000084DD434]
        rdx -= driver.base_addr;                //sub rdx, [rsp+0xA8] -- didn't find trace -> use base
        rax = 0;                //and rax, 0xFFFFFFFFC0000000
        rax = _rotl64(rax, 0x10);               //rol rax, 0x10
        rax ^= r9;              //xor rax, r9
        rax = _byteswap_uint64(rax);            //bswap rax
        rdx *= driver.Read<uintptr_t>(rax + 0x11);              //imul rdx, [rax+0x11]
        rax = r11;              //mov rax, r11
        rax -= driver.base_addr;                //sub rax, [rsp+0xA8] -- didn't find trace -> use base
        rax += 0xFFFFFFFFFFFF88EC;              //add rax, 0xFFFFFFFFFFFF88EC
        rdx += rax;             //add rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x12;           //shr rax, 0x12
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x24;           //shr rax, 0x24
        rdx ^= rax;             //xor rdx, rax
        rax = 0x4DBC160E13E56349;               //mov rax, 0x4DBC160E13E56349
        rdx *= rax;             //imul rdx, rax
        rax = driver.base_addr;                 //lea rax, [0xFFFFFFFFFD96F1A4]
        rdx ^= rax;             //xor rdx, rax
        rax = driver.base_addr;                 //lea rax, [0xFFFFFFFFFD96F074]
        rdx += rax;             //add rdx, rax
        return rdx;
    }
    case 11:
    {
        r10 = driver.Read<uintptr_t>(driver.base_addr + 0xAB6E1FC);             //mov r10, [0x00000000084DCF99]
        rax = 0;                //and rax, 0xFFFFFFFFC0000000
        rax = _rotl64(rax, 0x10);               //rol rax, 0x10
        rax ^= r10;             //xor rax, r10
        rax = _byteswap_uint64(rax);            //bswap rax
        rdx *= driver.Read<uintptr_t>(rax + 0x11);              //imul rdx, [rax+0x11]
        rax = driver.base_addr + 0x73A4FAE9;            //lea rax, [0x00000000713BE5C2]
        rax = ~rax;             //not rax
        rdx -= r11;             //sub rdx, r11
        rdx += rax;             //add rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x16;           //shr rax, 0x16
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x2C;           //shr rax, 0x2C
        rdx ^= rax;             //xor rdx, rax
        rax = 0x861DF3431C84C629;               //mov rax, 0x861DF3431C84C629
        rdx *= rax;             //imul rdx, rax
        rax = 0x714B44E8CE73C4F0;               //mov rax, 0x714B44E8CE73C4F0
        rdx -= rax;             //sub rdx, rax
        rax = driver.base_addr;                 //lea rax, [0xFFFFFFFFFD96EA3D]
        rcx = rax * 0xFFFFFFFFFFFFFFFE;                 //imul rcx, rax, 0xFFFFFFFFFFFFFFFE
        rax = 0x6F9175143B9ED737;               //mov rax, 0x6F9175143B9ED737
        rdx += rax;             //add rdx, rax
        rdx += rcx;             //add rdx, rcx
        return rdx;
    }
    case 12:
    {
        r13 = driver.base_addr + 0xD3DA;                //lea r13, [0xFFFFFFFFFD97BDAC]
        r10 = driver.Read<uintptr_t>(driver.base_addr + 0xAB6E1FC);             //mov r10, [0x00000000084DCB7F]
        rdx -= r11;             //sub rdx, r11
        rcx = r11;              //mov rcx, r11
        rcx = ~rcx;             //not rcx
        rax = driver.base_addr + 0x1F86111B;            //lea rax, [0x000000001D1CF744]
        rax = ~rax;             //not rax
        rcx *= rax;             //imul rcx, rax
        rax = rdx + r13 * 1;            //lea rax, [rdx+r13*1]
        rdx = rcx;              //mov rdx, rcx
        rdx ^= rax;             //xor rdx, rax
        rax = 0;                //and rax, 0xFFFFFFFFC0000000
        rax = _rotl64(rax, 0x10);               //rol rax, 0x10
        rax ^= r10;             //xor rax, r10
        rax = _byteswap_uint64(rax);            //bswap rax
        rdx *= driver.Read<uintptr_t>(rax + 0x11);              //imul rdx, [rax+0x11]
        rcx = driver.base_addr;                 //lea rcx, [0xFFFFFFFFFD96E7E2]
        rax = r11;              //mov rax, r11
        rax -= rcx;             //sub rax, rcx
        rcx = rax + 0xffffffffca7be9d9;                 //lea rcx, [rax-0x35841627]
        rcx += rdx;             //add rcx, rdx
        rax = rcx;              //mov rax, rcx
        rax >>= 0x18;           //shr rax, 0x18
        rcx ^= rax;             //xor rcx, rax
        rax = 0xFBA7ABC8BBB4629D;               //mov rax, 0xFBA7ABC8BBB4629D
        rdx = rcx;              //mov rdx, rcx
        rdx >>= 0x30;           //shr rdx, 0x30
        rdx ^= rcx;             //xor rdx, rcx
        rdx *= rax;             //imul rdx, rax
        rax = 0x1FE6307AA1F54B4D;               //mov rax, 0x1FE6307AA1F54B4D
        rdx *= rax;             //imul rdx, rax
        rax = 0x57A7A919AF723E1B;               //mov rax, 0x57A7A919AF723E1B
        rdx -= rax;             //sub rdx, rax
        return rdx;
    }
    case 13:
    {
        r9 = driver.Read<uintptr_t>(driver.base_addr + 0xAB6E1FC);              //mov r9, [0x00000000084DC6D2]
        rax = rdx;              //mov rax, rdx
        rax >>= 0x1A;           //shr rax, 0x1A
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x34;           //shr rax, 0x34
        rdx ^= rax;             //xor rdx, rax
        rax = 0x525F068BC2643DF7;               //mov rax, 0x525F068BC2643DF7
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0xD;            //shr rax, 0x0D
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x1A;           //shr rax, 0x1A
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x34;           //shr rax, 0x34
        rdx ^= rax;             //xor rdx, rax
        rax = 0;                //and rax, 0xFFFFFFFFC0000000
        rax = _rotl64(rax, 0x10);               //rol rax, 0x10
        rax ^= r9;              //xor rax, r9
        rax = _byteswap_uint64(rax);            //bswap rax
        rdx *= driver.Read<uintptr_t>(rax + 0x11);              //imul rdx, [rax+0x11]
        rax = 0x75DFF140FA1FB5BC;               //mov rax, 0x75DFF140FA1FB5BC
        rdx += rax;             //add rdx, rax
        rax = driver.base_addr;                 //lea rax, [0xFFFFFFFFFD96E148]
        rdx += rax;             //add rdx, rax
        rax = 0xE5945E699002C625;               //mov rax, 0xE5945E699002C625
        rdx *= rax;             //imul rdx, rax
        rax = driver.base_addr;                 //lea rax, [0xFFFFFFFFFD96E130]
        rdx ^= rax;             //xor rdx, rax
        return rdx;
    }
    case 14:
    {
        r13 = driver.base_addr + 0x73A4A654;            //lea r13, [0x00000000713B86F1]
        r10 = driver.Read<uintptr_t>(driver.base_addr + 0xAB6E1FC);             //mov r10, [0x00000000084DC222]
        rax = 0x75736E13202430E1;               //mov rax, 0x75736E13202430E1
        rdx *= rax;             //imul rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x26;           //shr rax, 0x26
        rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
        rdx ^= rax;             //xor rdx, rax
        rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
        rcx ^= r10;             //xor rcx, r10
        rcx = _byteswap_uint64(rcx);            //bswap rcx
        rdx *= driver.Read<uintptr_t>(rcx + 0x11);              //imul rdx, [rcx+0x11]
        rax = rdx;              //mov rax, rdx
        rax >>= 0x9;            //shr rax, 0x09
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x12;           //shr rax, 0x12
        rdx ^= rax;             //xor rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x24;           //shr rax, 0x24
        rdx ^= rax;             //xor rdx, rax
        rdx += r11;             //add rdx, r11
        rax = r11;              //mov rax, r11
        rax = ~rax;             //not rax
        rax *= r13;             //imul rax, r13
        rdx ^= rax;             //xor rdx, rax
        rax = 0xABD8E138F25E5687;               //mov rax, 0xABD8E138F25E5687
        rdx ^= rax;             //xor rdx, rax
        return rdx;
    }
    case 15:
    {
        rsi = 0xB656FAE057EB613B;               //mov rsi, 0xB656FAE057EB613B
        r10 = driver.Read<uintptr_t>(driver.base_addr + 0xAB6E1FC);             //mov r10, [0x00000000084DBE12]
        rdx *= rsi;             //imul rdx, rsi
        rax = rdx;              //mov rax, rdx
        rax >>= 0x21;           //shr rax, 0x21
        rdx ^= rax;             //xor rdx, rax
        rax = 0;                //and rax, 0xFFFFFFFFC0000000
        rax = _rotl64(rax, 0x10);               //rol rax, 0x10
        rax ^= r10;             //xor rax, r10
        rax = _byteswap_uint64(rax);            //bswap rax
        rdx *= driver.Read<uintptr_t>(rax + 0x11);              //imul rdx, [rax+0x11]
        rax = 0x5CA0A4447C245D90;               //mov rax, 0x5CA0A4447C245D90
        rdx -= rax;             //sub rdx, rax
        rdx -= r11;             //sub rdx, r11
        rax = 0xF071D0312866EB9D;               //mov rax, 0xF071D0312866EB9D
        rdx *= rax;             //imul rdx, rax
        rax = 0xFFFFFFFFFFFFF34A;               //mov rax, 0xFFFFFFFFFFFFF34A
        rax -= r11;             //sub rax, r11
        rax -= driver.base_addr;                //sub rax, [rsp+0xA8] -- didn't find trace -> use base
        rdx += rax;             //add rdx, rax
        rax = rdx;              //mov rax, rdx
        rax >>= 0x21;           //shr rax, 0x21
        rdx ^= rax;             //xor rdx, rax
        return rdx;
    }
    }
}
uint16_t get_bone_index(const Driver& driver, uint32_t bone_index)
{
    const uint64_t mb = driver.base_addr;
    uint64_t rax = mb, rbx = mb, rcx = mb, rdx = mb, rdi = mb, rsi = mb, r8 = mb, r9 = mb, r10 = mb, r11 = mb, r12 = mb, r13 = mb, r14 = mb, r15 = mb;
    rdi = bone_index;
    rcx = rdi * 0x13C8;
    rax = 0x2AC83BD095F98207;               //mov rax, 0x2AC83BD095F98207
    rax = _umul128(rax, rcx, (uintptr_t*)&rdx);             //mul rcx
    rax = rcx;              //mov rax, rcx
    r11 = driver.base_addr;                 //lea r11, [0xFFFFFFFFFD5609E2]
    rax -= rdx;             //sub rax, rdx
    r10 = 0xD1F23647CF68B0F;                //mov r10, 0xD1F23647CF68B0F
    rax >>= 0x1;            //shr rax, 0x01
    rax += rdx;             //add rax, rdx
    rax >>= 0xC;            //shr rax, 0x0C
    rax = rax * 0x1B6B;             //imul rax, rax, 0x1B6B
    rcx -= rax;             //sub rcx, rax
    rax = 0x6768ECB62DD904F3;               //mov rax, 0x6768ECB62DD904F3
    r8 = rcx * 0x1B6B;              //imul r8, rcx, 0x1B6B
    rax = _umul128(rax, r8, (uintptr_t*)&rdx);              //mul r8
    rdx >>= 0xC;            //shr rdx, 0x0C
    rax = rdx * 0x279C;             //imul rax, rdx, 0x279C
    r8 -= rax;              //sub r8, rax
    rax = 0x8888888888888889;               //mov rax, 0x8888888888888889
    rax = _umul128(rax, r8, (uintptr_t*)&rdx);              //mul r8
    rax = 0x1778A191BD684181;               //mov rax, 0x1778A191BD684181
    rdx >>= 0x4;            //shr rdx, 0x04
    rcx = rdx * 0x1E;               //imul rcx, rdx, 0x1E
    rax = _umul128(rax, r8, (uintptr_t*)&rdx);              //mul r8
    rax = r8;               //mov rax, r8
    rax -= rdx;             //sub rax, rdx
    rax >>= 0x1;            //shr rax, 0x01
    rax += rdx;             //add rax, rdx
    rax >>= 0x8;            //shr rax, 0x08
    rcx += rax;             //add rcx, rax
    rax = rcx * 0x3AA;              //imul rax, rcx, 0x3AA
    rcx = r8 * 0x3AC;               //imul rcx, r8, 0x3AC
    rcx -= rax;             //sub rcx, rax
    rax = driver.Read<uint16_t>(rcx + r11 * 1 + 0xAC49880);                 //movzx eax, word ptr [rcx+r11*1+0xAC49880]
    r8 = rax * 0x13C8;              //imul r8, rax, 0x13C8
    rax = r10;              //mov rax, r10
    rax = _umul128(rax, r8, (uintptr_t*)&rdx);              //mul r8
    rax = r10;              //mov rax, r10
    rdx >>= 0x9;            //shr rdx, 0x09
    rcx = rdx * 0x2705;             //imul rcx, rdx, 0x2705
    r8 -= rcx;              //sub r8, rcx
    r9 = r8 * 0x49D8;               //imul r9, r8, 0x49D8
    rax = _umul128(rax, r9, (uintptr_t*)&rdx);              //mul r9
    rdx >>= 0x9;            //shr rdx, 0x09
    rax = rdx * 0x2705;             //imul rax, rdx, 0x2705
    r9 -= rax;              //sub r9, rax
    rax = 0xA10BFDF49906A50F;               //mov rax, 0xA10BFDF49906A50F
    rax = _umul128(rax, r9, (uintptr_t*)&rdx);              //mul r9
    rcx = r9;               //mov rcx, r9
    r9 &= 0x1;             //and r9d, 0x01
    rdx >>= 0xC;            //shr rdx, 0x0C
    rax = rdx * 0x196F;             //imul rax, rdx, 0x196F
    rcx -= rax;             //sub rcx, rax
    rax = r9 + rcx * 2;             //lea rax, [r9+rcx*2]
    r12 = driver.Read<uint16_t>(r11 + rax * 2 + 0xAC50670);                 //movsx r12d, word ptr [r11+rax*2+0xAC50670]
    return r12;
}

constexpr auto timestamp = 0x645343CE;
constexpr auto ref_def_ptr = 0x12DC2F10;
constexpr auto name_array = 0x12DE1898;
constexpr auto name_array_pos = 0x5E70; // 0x4C70 for MW1(2019)
constexpr auto name_array_size = 0xD8;
constexpr auto loot_ptr = 0xFFFF80091D72B714;
constexpr auto camera_base = 0x134768A0;
constexpr auto camera_pos = 0x1F8;
constexpr auto local_index = 0x958F0;
constexpr auto local_index_pos = 0x2D0; // 0x1FC for MW1 (2019)
constexpr auto recoil = 0x0;
constexpr auto game_mode = 0x1021F9E0;
constexpr auto weapon_definitions = 0x12D40820;
constexpr auto distribute = 0xC1CAAB8;
constexpr auto visible_offset = 0xA80;
constexpr auto visible = 0x0;

namespace bone {
    constexpr auto bone_base = 0x0;
    constexpr auto size = 0x188;
    constexpr auto offset = 0xD8; //0xC0 for MW1(2019).
};

namespace player {
    constexpr auto size = 0x6448;
    constexpr auto valid = 0x0;
    constexpr auto pos = 0x7A0;
    constexpr auto team = 0x5CEE;
    constexpr auto stance = 0x0;
    constexpr auto weapon_index = 0x5D8A;
    constexpr auto dead_1 = 0x596C;
    constexpr auto dead_2 = 0x5D20;
};