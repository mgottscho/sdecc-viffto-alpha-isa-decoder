#include "decoder.hh"
#include "MyDecoder.hh"
#include <iostream>

using namespace AlphaISA;


bool
AlphaISA::Decoder::decodeInst(AlphaISA::ExtMachInst machInst)
{
    using namespace AlphaISAInst;
  switch (OPCODE) {
    
    case 0x8:  
      // LoadAddress::lda([' Ra = Rb + disp; '],{})
      
          std::cout << "lda" << std::endl;
          return 0; // Lda(machInst);
      break;
    
    case 0x9:  
      // LoadAddress::ldah([' Ra = Rb + (disp << 16); '],{})
      
          std::cout << "ldah" << std::endl;
          return 0; // Ldah(machInst);
      break;
    
    case 0xa:  
      // LoadOrNop::ldbu([' Ra_uq = Mem_ub; '],{})
      
       //{
       //    AlphaStaticInst *i = new Ldbu(machInst);
           if (RA == 31) {
               //i = makeNop(i);
               std::cout << "nop" << std::endl;
           } else
               std::cout << "ldbu" << std::endl;
        //   return i;
       //}
       return 0;
      break;
    
    case 0xc:  
      // LoadOrNop::ldwu([' Ra_uq = Mem_uw; '],{})
      
       //{
           //AlphaStaticInst *i = new Ldwu(machInst);
           if (RA == 31) {
            //   i = makeNop(i);
               std::cout << "nop" << std::endl;
           } else
               std::cout << "ldwu" << std::endl;
           //return i;
       //}
       return 0;
      break;
    
    case 0xb:  
    //MWG PICK UP WORK HERE
      // LoadOrNop::ldq_u([' Ra = Mem_uq; '],{'ea_code': ' EA = (Rb + disp) & ~7; '})
      
       /*{
           AlphaStaticInst *i = new Ldq_u(machInst);
           if (RA == 31) {
               i = makeNop(i);
           }
           return i;
       }*/
       std::cout << "ldq_u" << std::endl;
       return 0;
      break;
    
    case 0x23:  
      // LoadOrNop::ldt([' Fa = Mem_df; '],{})
      
       /*{
           AlphaStaticInst *i = new Ldt(machInst);
           if (RA == 31) {
               i = makeNop(i);
           }
           return i;
       }*/
       std::cout << "ldt" << std::endl;
       return 0;
      break;
    
    case 0x2a:  
      // LoadOrNop::ldl_l([' Ra_sl = Mem_sl; '],{'mem_flags': 'LLSC'})
      
       /*{
           AlphaStaticInst *i = new Ldl_l(machInst);
           if (RA == 31) {
               i = makeNop(i);
           }
           return i;
       }*/
       std::cout << "ldl_l" << std::endl;
       return 0;
      break;
    
    case 0x2b:  
      // LoadOrNop::ldq_l([' Ra_uq = Mem_uq; '],{'mem_flags': 'LLSC'})
      
       /*{
           AlphaStaticInst *i = new Ldq_l(machInst);
           if (RA == 31) {
               i = makeNop(i);
           }
           return i;
       }*/
       std::cout << "ldq_l" << std::endl;
       return 0;
      break;
    
    case 0x28:  
      // LoadOrPrefetch::ldl([' Ra_sl = Mem_sl; '],{})
      
       {
           if (RA != 31) {
               std::cout << "ldl" << std::endl; return 0; // Ldl(machInst);
           }
           else {
               std::cout << "ldlprefetch" << std::endl; return 0; // LdlPrefetch(machInst);
           }
       }
      break;
    
    case 0x29:  
      // LoadOrPrefetch::ldq([' Ra_uq = Mem_uq; '],{'pf_flags': 'EVICT_NEXT'})
      
       {
           if (RA != 31) {
               std::cout << "ldq" << std::endl; return 0; // Ldq(machInst);
           }
           else {
               std::cout << "ldqprefetch" << std::endl; return 0; // LdqPrefetch(machInst);
           }
       }
      break;
    
    case 0x22:  
      // LoadOrPrefetch::lds([' Fa_uq = s_to_t(Mem_ul); '],{'pf_flags': 'PF_EXCLUSIVE', 'inst_flags': 'IsFloating'})
      
       {
           if (RA != 31) {
               std::cout << "lds" << std::endl; return 0; // Lds(machInst);
           }
           else {
               std::cout << "ldsprefetch" << std::endl; return 0; // LdsPrefetch(machInst);
           }
       }
      break;
    
    case 0xe:  
      // Store::stb([' Mem_ub = Ra<7:0>; '],{})
      
          std::cout << "stb" << std::endl; return 0; // Stb(machInst);
      break;
    
    case 0xd:  
      // Store::stw([' Mem_uw = Ra<15:0>; '],{})
      
          std::cout << "stw" << std::endl; return 0; // Stw(machInst);
      break;
    
    case 0x2c:  
      // Store::stl([' Mem_ul = Ra<31:0>; '],{})
      
          std::cout << "stl" << std::endl; return 0; // Stl(machInst);
      break;
    
    case 0x2d:  
      // Store::stq([' Mem_uq = Ra_uq; '],{})
      
          std::cout << "stq" << std::endl; return 0; // Stq(machInst);
      break;
    
    case 0xf:  
      // Store::stq_u([' Mem_uq = Ra_uq; ', ' EA = (Rb + disp) & ~7; '],{})
      
          std::cout << "stq_u" << std::endl; return 0; // Stq_u(machInst);
      break;
    
    case 0x26:  
      // Store::sts([' Mem_ul = t_to_s(Fa_uq); '],{})
      
          std::cout << "sts" << std::endl; return 0; // Sts(machInst);
      break;
    
    case 0x27:  
      // Store::stt([' Mem_df = Fa; '],{})
      
          std::cout << "stt" << std::endl; return 0; // Stt(machInst);
      break;
    
    case 0x2e:  
      // StoreCond::stl_c([' Mem_ul = Ra<31:0>; ', '\n                        uint64_t tmp = write_result;\n                        // see stq_c\n                        Ra = (tmp == 0 || tmp == 1) ? tmp : Ra;\n                        if (tmp == 1) {\n                            xc->setStCondFailures(0);\n                        }\n                    '],{'inst_flags': 'IsStoreConditional', 'mem_flags': 'LLSC'})
      
          std::cout << "stl_c" << std::endl; return 0; // Stl_c(machInst);
      break;
    
    case 0x2f:  
      // StoreCond::stq_c([' Mem_uq = Ra; ', "\n                        uint64_t tmp = write_result;\n                        // If the write operation returns 0 or 1, then\n                        // this was a conventional store conditional,\n                        // and the value indicates the success/failure\n                        // of the operation.  If another value is\n                        // returned, then this was a Turbolaser\n                        // mailbox access, and we don't update the\n                        // result register at all.\n                        Ra = (tmp == 0 || tmp == 1) ? tmp : Ra;\n                        if (tmp == 1) {\n                            // clear failure counter... this is\n                            // non-architectural and for debugging\n                            // only.\n                            xc->setStCondFailures(0);\n                        }\n                    "],{'inst_flags': 'IsStoreConditional', 'mem_flags': 'LLSC'})
      
          std::cout << "stq_c" << std::endl; return 0; // Stq_c(machInst);
      break;
    
    case 0x10:
      switch (INTFUNC) {
        
        case 0x0:  
          // IntegerOperate::addl([' Rc_sl = Ra_sl + Rb_or_imm_sl; '],{})
          
           //{
               //AlphaStaticInst *i =
                   //(IMM) ? (AlphaStaticInst *)new AddlImm(machInst)
                         //: (AlphaStaticInst *)new Addl(machInst);
               if (RC == 31) {
             //      i = makeNop(i);
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "addlimm" << std::endl
                         : std::cout << "addl" << std::endl;
               }
               //return i;
           //}
           return 0;
          break;
        
        case 0x40:  
          // IntegerOperate::addlv(['\n                int32_t tmp  = Ra_sl + Rb_or_imm_sl;\n                // signed overflow occurs when operands have same sign\n                // and sign of result does not match.\n                if (Ra_sl<31:> == Rb_or_imm_sl<31:> && tmp<31:> != Ra_sl<31:>)\n                    fault = new IntegerOverflowFault;\n                Rc_sl = tmp;\n            '],{})
          
           //{
               //AlphaStaticInst *i =
                  // (IMM) ? (AlphaStaticInst *)new AddlvImm(machInst)
                         //: (AlphaStaticInst *)new Addlv(machInst);
               if (RC == 31) {
                   //i = makeNop(i);
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "addlvimm" << std::endl
                         : std::cout << "addlv" << std::endl;
               }
            //   return i;
           //}
           return 0;
          break;
        
        case 0x2:  
          // IntegerOperate::s4addl([' Rc_sl = (Ra_sl << 2) + Rb_or_imm_sl; '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new S4addlImm(machInst)
                         : (AlphaStaticInst *)new S4addl(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
               if (RC == 31) {
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "s4addlimm" << std::endl
                         : std::cout << "s4addl" << std::endl;
               }
               return 0;
          break;
        
        case 0x12:  
          // IntegerOperate::s8addl([' Rc_sl = (Ra_sl << 3) + Rb_or_imm_sl; '],{})
          
           //{
            //   AlphaStaticInst *i =
                 //  (IMM) ? (AlphaStaticInst *)new S8addlImm(machInst)
                //         : (AlphaStaticInst *)new S8addl(machInst);
               if (RC == 31) {
               //    i = makeNop(i);
                    std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "s8addlimm" << std::endl
                         : std::cout << "s8addl" << std::endl;
               }
               //return i;
           //}
           return 0;
          break;
        
        case 0x20:  
          // IntegerOperate::addq([' Rc = Ra + Rb_or_imm; '],{})
          
          /* {
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new AddqImm(machInst)
                         : (AlphaStaticInst *)new Addq(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
               if (RC == 31) {
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "addqimm" << std::endl
                         : std::cout << "addq" << std::endl;
               }
               return 0;
          break;
        
        case 0x60:  
          // IntegerOperate::addqv(['\n                uint64_t tmp = Ra + Rb_or_imm;\n                // signed overflow occurs when operands have same sign\n                // and sign of result does not match.\n                if (Ra<63:> == Rb_or_imm<63:> && tmp<63:> != Ra<63:>)\n                    fault = new IntegerOverflowFault;\n                Rc = tmp;\n            '],{})
          
           //{
               //AlphaStaticInst *i =
                   //(IMM) ? (AlphaStaticInst *)new AddqvImm(machInst)
                         //: (AlphaStaticInst *)new Addqv(machInst);
               if (RC == 31) {
                   //i = makeNop(i);
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "addqvimm" << std::endl
                         : std::cout << "addqv" << std::endl;
               }
               //return i;
           //}
           return 0;
          break;
        
        case 0x22:  
          // IntegerOperate::s4addq([' Rc = (Ra << 2) + Rb_or_imm; '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new S4addqImm(machInst)
                         : (AlphaStaticInst *)new S4addq(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
               if (RC == 31) {
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "s4addqimm" << std::endl
                         : std::cout << "s4addq" << std::endl;
               }
           return 0;
          break;
        
        case 0x32:  
          // IntegerOperate::s8addq([' Rc = (Ra << 3) + Rb_or_imm; '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new S8addqImm(machInst)
                         : (AlphaStaticInst *)new S8addq(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
               if (RC == 31) {
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "s8addqimm" << std::endl
                         : std::cout << "s8addq" << std::endl;
               }
               return 0;
          break;
        
        case 0x9:  
          // IntegerOperate::subl([' Rc_sl = Ra_sl - Rb_or_imm_sl; '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new SublImm(machInst)
                         : (AlphaStaticInst *)new Subl(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
               if (RC == 31) {
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "sublimm" << std::endl
                         : std::cout << "subl" << std::endl;
               }
               return 0;
          break;
        
        case 0x49:  
          // IntegerOperate::sublv(['\n                int32_t tmp  = Ra_sl - Rb_or_imm_sl;\n                // signed overflow detection is same as for add,\n                // except we need to look at the *complemented*\n                // sign bit of the subtrahend (Rb), i.e., if the initial\n                // signs are the *same* then no overflow can occur\n                if (Ra_sl<31:> != Rb_or_imm_sl<31:> && tmp<31:> != Ra_sl<31:>)\n                    fault = new IntegerOverflowFault;\n                Rc_sl = tmp;\n            '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new SublvImm(machInst)
                         : (AlphaStaticInst *)new Sublv(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
               if (RC == 31) {
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "sublvimm" << std::endl
                         : std::cout << "sublv" << std::endl;
               }
               return 0;
          break;
        
        case 0xb:  
          // IntegerOperate::s4subl([' Rc_sl = (Ra_sl << 2) - Rb_or_imm_sl; '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new S4sublImm(machInst)
                         : (AlphaStaticInst *)new S4subl(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
               if (RC == 31) {
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "s4sublimm" << std::endl
                         : std::cout << "s4subl" << std::endl;
               }
               return 0;
          break;
        
        case 0x1b:  
          // IntegerOperate::s8subl([' Rc_sl = (Ra_sl << 3) - Rb_or_imm_sl; '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new S8sublImm(machInst)
                         : (AlphaStaticInst *)new S8subl(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
               if (RC == 31) {
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "s8sublimm" << std::endl
                         : std::cout << "s8subl" << std::endl;
               }
               return 0;
          break;
        
        case 0x29:  
          // IntegerOperate::subq([' Rc = Ra - Rb_or_imm; '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new SubqImm(machInst)
                         : (AlphaStaticInst *)new Subq(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
               if (RC == 31) {
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "subqimm" << std::endl
                         : std::cout << "subq" << std::endl;
               }
               return 0;
          break;
        
        case 0x69:  
          // IntegerOperate::subqv(['\n                uint64_t tmp  = Ra - Rb_or_imm;\n                // signed overflow detection is same as for add,\n                // except we need to look at the *complemented*\n                // sign bit of the subtrahend (Rb), i.e., if the initial\n                // signs are the *same* then no overflow can occur\n                if (Ra<63:> != Rb_or_imm<63:> && tmp<63:> != Ra<63:>)\n                    fault = new IntegerOverflowFault;\n                Rc = tmp;\n            '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new SubqvImm(machInst)
                         : (AlphaStaticInst *)new Subqv(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
               if (RC == 31) {
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "subqvimm" << std::endl
                         : std::cout << "subqv" << std::endl;
               }
               return 0;
          break;
        
        case 0x2b:  
          // IntegerOperate::s4subq([' Rc = (Ra << 2) - Rb_or_imm; '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new S4subqImm(machInst)
                         : (AlphaStaticInst *)new S4subq(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
               if (RC == 31) {
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "s4subqimm" << std::endl
                         : std::cout << "s4subq" << std::endl;
               }
               return 0;
          break;
        
        case 0x3b:  
          // IntegerOperate::s8subq([' Rc = (Ra << 3) - Rb_or_imm; '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new S8subqImm(machInst)
                         : (AlphaStaticInst *)new S8subq(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
               if (RC == 31) {
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "s8subqimm" << std::endl
                         : std::cout << "s8subq" << std::endl;
               }
               return 0;
          break;
        
        case 0x2d:  
          // IntegerOperate::cmpeq([' Rc = (Ra == Rb_or_imm); '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new CmpeqImm(machInst)
                         : (AlphaStaticInst *)new Cmpeq(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
               if (RC == 31) {
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "cmpeqimm" << std::endl
                         : std::cout << "cmpeq" << std::endl;
               }
               return 0;
          break;
        
        case 0x6d:  
          // IntegerOperate::cmple([' Rc = (Ra_sq <= Rb_or_imm_sq); '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new CmpleImm(machInst)
                         : (AlphaStaticInst *)new Cmple(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
               if (RC == 31) {
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "cmpleimm" << std::endl
                         : std::cout << "cmple" << std::endl;
               }
               return 0;
          break;
        
        case 0x4d:  
          // IntegerOperate::cmplt([' Rc = (Ra_sq <  Rb_or_imm_sq); '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new CmpltImm(machInst)
                         : (AlphaStaticInst *)new Cmplt(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
               if (RC == 31) {
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "cmpltimm" << std::endl
                         : std::cout << "cmplt" << std::endl;
               }
               return 0;
          break;
        
        case 0x3d:  
          // IntegerOperate::cmpule([' Rc = (Ra_uq <= Rb_or_imm_uq); '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new CmpuleImm(machInst)
                         : (AlphaStaticInst *)new Cmpule(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
               if (RC == 31) {
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "cmpuleimm" << std::endl
                         : std::cout << "cmpule" << std::endl;
               }
               return 0;
          break;
        
        case 0x1d:  
          // IntegerOperate::cmpult([' Rc = (Ra_uq <  Rb_or_imm_uq); '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new CmpultImm(machInst)
                         : (AlphaStaticInst *)new Cmpult(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
               if (RC == 31) {
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "cmpultimm" << std::endl
                         : std::cout << "cmpult" << std::endl;
               }
               return 0;
          break;
        
        case 0xf:  
          // IntegerOperate::cmpbge(['\n                int hi = 7;\n                int lo = 0;\n                uint64_t tmp = 0;\n                for (int i = 0; i < 8; ++i) {\n                    tmp |= (Ra_uq<hi:lo> >= Rb_or_imm_uq<hi:lo>) << i;\n                    hi += 8;\n                    lo += 8;\n                }\n                Rc = tmp;\n            '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new CmpbgeImm(machInst)
                         : (AlphaStaticInst *)new Cmpbge(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
               if (RC == 31) {
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "cmpbgeimm" << std::endl
                         : std::cout << "cmpbge" << std::endl;
               }
               return 0;
          break;
        
        default:
          
          // Unknown::unknown(([], {}))
          std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
          break;
        }
      
    case 0x11:
      switch (INTFUNC) {
        
        case 0x0:  
          // IntegerOperate::and([' Rc = Ra & Rb_or_imm; '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new AndImm(machInst)
                         : (AlphaStaticInst *)new And(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
               if (RC == 31) {
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "andimm" << std::endl
                         : std::cout << "and" << std::endl;
               }
               return 0;
          break;
        
        case 0x8:  
          // IntegerOperate::bic([' Rc = Ra & ~Rb_or_imm; '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new BicImm(machInst)
                         : (AlphaStaticInst *)new Bic(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
               if (RC == 31) {
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "bicimm" << std::endl
                         : std::cout << "bic" << std::endl;
               }
               return 0;
          break;
        
        case 0x20:  
          // IntegerOperate::bis([' Rc = Ra | Rb_or_imm; '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new BisImm(machInst)
                         : (AlphaStaticInst *)new Bis(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
               if (RC == 31) {
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "bisimm" << std::endl
                         : std::cout << "bis" << std::endl;
               }
               return 0;
          break;
        
        case 0x28:  
          // IntegerOperate::ornot([' Rc = Ra | ~Rb_or_imm; '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new OrnotImm(machInst)
                         : (AlphaStaticInst *)new Ornot(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
               if (RC == 31) {
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "ornotimm" << std::endl
                         : std::cout << "ornot" << std::endl;
               }
               return 0;
          break;
        
        case 0x40:  
          // IntegerOperate::xor([' Rc = Ra ^ Rb_or_imm; '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new XorImm(machInst)
                         : (AlphaStaticInst *)new Xor(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
               if (RC == 31) {
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "xorimm" << std::endl
                         : std::cout << "xor" << std::endl;
               }
               return 0;
          break;
        
        case 0x48:  
          // IntegerOperate::eqv([' Rc = Ra ^ ~Rb_or_imm; '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new EqvImm(machInst)
                         : (AlphaStaticInst *)new Eqv(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
               if (RC == 31) {
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "eqvimm" << std::endl
                         : std::cout << "eqv" << std::endl;
               }
               return 0;
          break;
        
        case 0x14:  
          // IntegerOperate::cmovlbs([' Rc = ((Ra & 1) == 1) ? Rb_or_imm : Rc; '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new CmovlbsImm(machInst)
                         : (AlphaStaticInst *)new Cmovlbs(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
               if (RC == 31) {
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "cmovlbsimm" << std::endl
                         : std::cout << "cmovlbs" << std::endl;
               }
               return 0;
          break;
        
        case 0x16:  
          // IntegerOperate::cmovlbc([' Rc = ((Ra & 1) == 0) ? Rb_or_imm : Rc; '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new CmovlbcImm(machInst)
                         : (AlphaStaticInst *)new Cmovlbc(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
               if (RC == 31) {
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "cmovlbcimm" << std::endl
                         : std::cout << "cmovlbc" << std::endl;
               }
               return 0;
          break;
        
        case 0x24:  
          // IntegerOperate::cmoveq([' Rc = (Ra == 0) ? Rb_or_imm : Rc; '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new CmoveqImm(machInst)
                         : (AlphaStaticInst *)new Cmoveq(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
               if (RC == 31) {
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "cmoveqimm" << std::endl
                         : std::cout << "cmoveq" << std::endl;
               }
               return 0;
          break;
        
        case 0x26:  
          // IntegerOperate::cmovne([' Rc = (Ra != 0) ? Rb_or_imm : Rc; '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new CmovneImm(machInst)
                         : (AlphaStaticInst *)new Cmovne(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
               if (RC == 31) {
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "cmovneimm" << std::endl
                         : std::cout << "cmovne" << std::endl;
               }
               return 0;
          break;
        
        case 0x44:  
          // IntegerOperate::cmovlt([' Rc = (Ra_sq <  0) ? Rb_or_imm : Rc; '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new CmovltImm(machInst)
                         : (AlphaStaticInst *)new Cmovlt(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
               if (RC == 31) {
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "cmovltimm" << std::endl
                         : std::cout << "cmovlt" << std::endl;
               }
               return 0;
          break;
        
        case 0x46:  
          // IntegerOperate::cmovge([' Rc = (Ra_sq >= 0) ? Rb_or_imm : Rc; '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new CmovgeImm(machInst)
                         : (AlphaStaticInst *)new Cmovge(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
               if (RC == 31) {
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "cmovgeimm" << std::endl
                         : std::cout << "cmovge" << std::endl;
               }
               return 0;
          break;
        
        case 0x64:  
          // IntegerOperate::cmovle([' Rc = (Ra_sq <= 0) ? Rb_or_imm : Rc; '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new CmovleImm(machInst)
                         : (AlphaStaticInst *)new Cmovle(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
               if (RC == 31) {
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "cmovleimm" << std::endl
                         : std::cout << "cmovle" << std::endl;
               }
               return 0;
          break;
        
        case 0x66:  
          // IntegerOperate::cmovgt([' Rc = (Ra_sq >  0) ? Rb_or_imm : Rc; '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new CmovgtImm(machInst)
                         : (AlphaStaticInst *)new Cmovgt(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
               if (RC == 31) {
                   std::cout << "nop" << std::endl;
               } else {
                   (IMM) ? std::cout << "cmovgtimm" << std::endl
                         : std::cout << "cmovgt" << std::endl;
               }
               return 0;
          break;
        
        case 0x61:
          switch (RA) {
            
            case 0x1f:  
              // IntegerOperate::amask([' Rc = Rb_or_imm & ~ULL(0x17); '],{})
              
               /*{
                   AlphaStaticInst *i =
                       (IMM) ? (AlphaStaticInst *)new AmaskImm(machInst)
                             : (AlphaStaticInst *)new Amask(machInst);
                   if (RC == 31) {
                       i = makeNop(i);
                   }
                   return i;
               }*/
                   if (RC == 31) {
                       std::cout << "nop" << std::endl;
                   } else {
                       (IMM) ? std::cout << "amaskimm" << std::endl
                             : std::cout << "amask" << std::endl;
                   }
                   return 0;
              break;
            
            default:
              
              // Unknown::unknown(([], {}))
              std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
              break;
            }
          
        case 0x6c:
          switch (RA) {
            
            case 0x1f:
              switch (IMM) {
                
                case 0x1:
                  switch (INTIMM) {
                    
                    case 0x1:  
                      // IntegerOperate::implver([' Rc = FullSystem ? 1 : 2 '],{})
                      
                       /*{
                           AlphaStaticInst *i = new Implver(machInst);
                           if (RC == 31) {
                               i = makeNop(i);
                           }
                           return i;
                       }*/
                           if (RC == 31) {
                               std::cout << "nop" << std::endl;
                           } else {
                               std::cout << "implver" << std::endl;
                           }
                           return 0;
                      break;
                    
                    default:
                      
                      // Unknown::unknown(([], {}))
                      std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
                      break;
                    }
                  
                default:
                  
                  // Unknown::unknown(([], {}))
                  std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
                  break;
                }
              
            default:
              
              // Unknown::unknown(([], {}))
              std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
              break;
            }
          
        case 0x25:  
          // WarnUnimpl::eleven25(([], {}))
                
              std::cout << "eleven25" << std::endl; return 0; // WarnUnimplemented("eleven25", machInst);
          break;
        
        default:
          
          // Unknown::unknown(([], {}))
          std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
          break;
        }
      
    case 0x12:
      switch (INTFUNC) {
        
        case 0x39:  
          // IntegerOperate::sll([' Rc = Ra << Rb_or_imm<5:0>; '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new SllImm(machInst)
                         : (AlphaStaticInst *)new Sll(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
                   if (RC == 31) {
                       std::cout << "nop" << std::endl;
                   } else {
                       (IMM) ? std::cout << "sllimm" << std::endl
                             : std::cout << "sll" << std::endl;
                   }
                   return 0;
          break;
        
        case 0x34:  
          // IntegerOperate::srl([' Rc = Ra_uq >> Rb_or_imm<5:0>; '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new SrlImm(machInst)
                         : (AlphaStaticInst *)new Srl(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
                   if (RC == 31) {
                       std::cout << "nop" << std::endl;
                   } else {
                       (IMM) ? std::cout << "srlimm" << std::endl
                             : std::cout << "srl" << std::endl;
                   }
                   return 0;
          break;
        
        case 0x3c:  
          // IntegerOperate::sra([' Rc = Ra_sq >> Rb_or_imm<5:0>; '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new SraImm(machInst)
                         : (AlphaStaticInst *)new Sra(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
                   if (RC == 31) {
                       std::cout << "nop" << std::endl;
                   } else {
                       (IMM) ? std::cout << "sraimm" << std::endl
                             : std::cout << "sra" << std::endl;
                   }
                   return 0;
          break;
        
        case 0x2:  
          // IntegerOperate::mskbl([' Rc = Ra & ~(mask( 8) << (Rb_or_imm<2:0> * 8)); '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new MskblImm(machInst)
                         : (AlphaStaticInst *)new Mskbl(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
                   if (RC == 31) {
                       std::cout << "nop" << std::endl;
                   } else {
                       (IMM) ? std::cout << "mskblimm" << std::endl
                             : std::cout << "mskbl" << std::endl;
                   }
                   return 0;
          break;
        
        case 0x12:  
          // IntegerOperate::mskwl([' Rc = Ra & ~(mask(16) << (Rb_or_imm<2:0> * 8)); '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new MskwlImm(machInst)
                         : (AlphaStaticInst *)new Mskwl(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
                   if (RC == 31) {
                       std::cout << "nop" << std::endl;
                   } else {
                       (IMM) ? std::cout << "mskwlimm" << std::endl
                             : std::cout << "mskwl" << std::endl;
                   }
                   return 0;
          break;
        
        case 0x22:  
          // IntegerOperate::mskll([' Rc = Ra & ~(mask(32) << (Rb_or_imm<2:0> * 8)); '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new MskllImm(machInst)
                         : (AlphaStaticInst *)new Mskll(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
                   if (RC == 31) {
                       std::cout << "nop" << std::endl;
                   } else {
                       (IMM) ? std::cout << "mskllimm" << std::endl
                             : std::cout << "mskll" << std::endl;
                   }
                   return 0;
          break;
        
        case 0x32:  
          // IntegerOperate::mskql([' Rc = Ra & ~(mask(64) << (Rb_or_imm<2:0> * 8)); '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new MskqlImm(machInst)
                         : (AlphaStaticInst *)new Mskql(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
                   if (RC == 31) {
                       std::cout << "nop" << std::endl;
                   } else {
                       (IMM) ? std::cout << "mskqlimm" << std::endl
                             : std::cout << "mskql" << std::endl;
                   }
                   return 0;
          break;
        
        case 0x52:  
          // IntegerOperate::mskwh(['\n                int bv = Rb_or_imm<2:0>;\n                Rc =  bv ? (Ra & ~(mask(16) >> (64 - 8 * bv))) : Ra;\n            '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new MskwhImm(machInst)
                         : (AlphaStaticInst *)new Mskwh(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
                   if (RC == 31) {
                       std::cout << "nop" << std::endl;
                   } else {
                       (IMM) ? std::cout << "mskwhimm" << std::endl
                             : std::cout << "mskwh" << std::endl;
                   }
                   return 0;
          break;
        
        case 0x62:  
          // IntegerOperate::msklh(['\n                int bv = Rb_or_imm<2:0>;\n                Rc =  bv ? (Ra & ~(mask(32) >> (64 - 8 * bv))) : Ra;\n            '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new MsklhImm(machInst)
                         : (AlphaStaticInst *)new Msklh(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
                   if (RC == 31) {
                       std::cout << "nop" << std::endl;
                   } else {
                       (IMM) ? std::cout << "msklhimm" << std::endl
                             : std::cout << "msklh" << std::endl;
                   }
                   return 0;
          break;
        
        case 0x72:  
          // IntegerOperate::mskqh(['\n                int bv = Rb_or_imm<2:0>;\n                Rc =  bv ? (Ra & ~(mask(64) >> (64 - 8 * bv))) : Ra;\n            '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new MskqhImm(machInst)
                         : (AlphaStaticInst *)new Mskqh(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
                   if (RC == 31) {
                       std::cout << "nop" << std::endl;
                   } else {
                       (IMM) ? std::cout << "mskqhimm" << std::endl
                             : std::cout << "mskqh" << std::endl;
                   }
                   return 0;
          break;
        
        case 0x6:  
          // IntegerOperate::extbl([' Rc = (Ra_uq >> (Rb_or_imm<2:0> * 8))< 7:0>; '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new ExtblImm(machInst)
                         : (AlphaStaticInst *)new Extbl(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
                   if (RC == 31) {
                       std::cout << "nop" << std::endl;
                   } else {
                       (IMM) ? std::cout << "extblimm" << std::endl
                             : std::cout << "extbl" << std::endl;
                   }
                   return 0;
          break;
        
        case 0x16:  
          // IntegerOperate::extwl([' Rc = (Ra_uq >> (Rb_or_imm<2:0> * 8))<15:0>; '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new ExtwlImm(machInst)
                         : (AlphaStaticInst *)new Extwl(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
                   if (RC == 31) {
                       std::cout << "nop" << std::endl;
                   } else {
                       (IMM) ? std::cout << "extwlimm" << std::endl
                             : std::cout << "extwl" << std::endl;
                   }
                   return 0;
          break;
        
        case 0x26:  
          // IntegerOperate::extll([' Rc = (Ra_uq >> (Rb_or_imm<2:0> * 8))<31:0>; '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new ExtllImm(machInst)
                         : (AlphaStaticInst *)new Extll(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
                   if (RC == 31) {
                       std::cout << "nop" << std::endl;
                   } else {
                       (IMM) ? std::cout << "extllimm" << std::endl
                             : std::cout << "extll" << std::endl;
                   }
                   return 0;
          break;
        
        case 0x36:  
          // IntegerOperate::extql([' Rc = (Ra_uq >> (Rb_or_imm<2:0> * 8)); '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new ExtqlImm(machInst)
                         : (AlphaStaticInst *)new Extql(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
                   if (RC == 31) {
                       std::cout << "nop" << std::endl;
                   } else {
                       (IMM) ? std::cout << "extqlimm" << std::endl
                             : std::cout << "extql" << std::endl;
                   }
                   return 0;
          break;
        
        case 0x5a:  
          // IntegerOperate::extwh(['\n                Rc = (Ra << (64 - (Rb_or_imm<2:0> * 8))<5:0>)<15:0>; '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new ExtwhImm(machInst)
                         : (AlphaStaticInst *)new Extwh(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
                   if (RC == 31) {
                       std::cout << "nop" << std::endl;
                   } else {
                       (IMM) ? std::cout << "extwhimm" << std::endl
                             : std::cout << "extwh" << std::endl;
                   }
                   return 0;
          break;
        
        case 0x6a:  
          // IntegerOperate::extlh(['\n                Rc = (Ra << (64 - (Rb_or_imm<2:0> * 8))<5:0>)<31:0>; '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new ExtlhImm(machInst)
                         : (AlphaStaticInst *)new Extlh(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
                   if (RC == 31) {
                       std::cout << "nop" << std::endl;
                   } else {
                       (IMM) ? std::cout << "extlhimm" << std::endl
                             : std::cout << "extlh" << std::endl;
                   }
                   return 0;
          break;
        
        case 0x7a:  
          // IntegerOperate::extqh(['\n                Rc = (Ra << (64 - (Rb_or_imm<2:0> * 8))<5:0>); '],{})
          
/*           {
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new ExtqhImm(machInst)
                         : (AlphaStaticInst *)new Extqh(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
                   if (RC == 31) {
                       std::cout << "nop" << std::endl;
                   } else {
                       (IMM) ? std::cout << "extqhimm" << std::endl
                             : std::cout << "extqh" << std::endl;
                   }
                   return 0;
          break;
        
        case 0xb:  
          // IntegerOperate::insbl([' Rc = Ra< 7:0> << (Rb_or_imm<2:0> * 8); '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new InsblImm(machInst)
                         : (AlphaStaticInst *)new Insbl(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
                   if (RC == 31) {
                       std::cout << "nop" << std::endl;
                   } else {
                       (IMM) ? std::cout << "insblimm" << std::endl
                             : std::cout << "insbl" << std::endl;
                   }
                   return 0;
          break;
        
        case 0x1b:  
          // IntegerOperate::inswl([' Rc = Ra<15:0> << (Rb_or_imm<2:0> * 8); '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new InswlImm(machInst)
                         : (AlphaStaticInst *)new Inswl(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
                   if (RC == 31) {
                       std::cout << "nop" << std::endl;
                   } else {
                       (IMM) ? std::cout << "inswlimm" << std::endl
                             : std::cout << "inswl" << std::endl;
                   }
                   return 0;
          break;
        
        case 0x2b:  
          // IntegerOperate::insll([' Rc = Ra<31:0> << (Rb_or_imm<2:0> * 8); '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new InsllImm(machInst)
                         : (AlphaStaticInst *)new Insll(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
                   if (RC == 31) {
                       std::cout << "nop" << std::endl;
                   } else {
                       (IMM) ? std::cout << "insllimm" << std::endl
                             : std::cout << "insll" << std::endl;
                   }
                   return 0;
          break;
        
        case 0x3b:  
          // IntegerOperate::insql([' Rc = Ra       << (Rb_or_imm<2:0> * 8); '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new InsqlImm(machInst)
                         : (AlphaStaticInst *)new Insql(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
                   if (RC == 31) {
                       std::cout << "nop" << std::endl;
                   } else {
                       (IMM) ? std::cout << "insqlimm" << std::endl
                             : std::cout << "insql" << std::endl;
                   }
                   return 0;
          break;
        
        case 0x57:  
          // IntegerOperate::inswh(['\n                int bv = Rb_or_imm<2:0>;\n                Rc = bv ? (Ra_uq<15:0> >> (64 - 8 * bv)) : 0;\n            '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new InswhImm(machInst)
                         : (AlphaStaticInst *)new Inswh(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
                   if (RC == 31) {
                       std::cout << "nop" << std::endl;
                   } else {
                       (IMM) ? std::cout << "inswhimm" << std::endl
                             : std::cout << "inswh" << std::endl;
                   }
                   return 0;
          break;
        
        case 0x67:  
          // IntegerOperate::inslh(['\n                int bv = Rb_or_imm<2:0>;\n                Rc = bv ? (Ra_uq<31:0> >> (64 - 8 * bv)) : 0;\n            '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new InslhImm(machInst)
                         : (AlphaStaticInst *)new Inslh(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
                   if (RC == 31) {
                       std::cout << "nop" << std::endl;
                   } else {
                       (IMM) ? std::cout << "inslhimm" << std::endl
                             : std::cout << "inslh" << std::endl;
                   }
                   return 0;
          break;
        
        case 0x77:  
          // IntegerOperate::insqh(['\n                int bv = Rb_or_imm<2:0>;\n                Rc = bv ? (Ra_uq       >> (64 - 8 * bv)) : 0;\n            '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new InsqhImm(machInst)
                         : (AlphaStaticInst *)new Insqh(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
                   if (RC == 31) {
                       std::cout << "nop" << std::endl;
                   } else {
                       (IMM) ? std::cout << "insqhimm" << std::endl
                             : std::cout << "insqh" << std::endl;
                   }
                   return 0;
          break;
        
        case 0x30:  
          // IntegerOperate::zap(['\n                uint64_t zapmask = 0;\n                for (int i = 0; i < 8; ++i) {\n                    if (Rb_or_imm<i:>)\n                        zapmask |= (mask(8) << (i * 8));\n                }\n                Rc = Ra & ~zapmask;\n            '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new ZapImm(machInst)
                         : (AlphaStaticInst *)new Zap(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
                   if (RC == 31) {
                       std::cout << "nop" << std::endl;
                   } else {
                       (IMM) ? std::cout << "zapimm" << std::endl
                             : std::cout << "zap" << std::endl;
                   }
                   return 0;
          break;
        
        case 0x31:  
          // IntegerOperate::zapnot(['\n                uint64_t zapmask = 0;\n                for (int i = 0; i < 8; ++i) {\n                    if (!Rb_or_imm<i:>)\n                        zapmask |= (mask(8) << (i * 8));\n                }\n                Rc = Ra & ~zapmask;\n            '],{})
          
           /*{
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new ZapnotImm(machInst)
                         : (AlphaStaticInst *)new Zapnot(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }*/
                   if (RC == 31) {
                       std::cout << "nop" << std::endl;
                   } else {
                       (IMM) ? std::cout << "zapnotimm" << std::endl
                             : std::cout << "zapnot" << std::endl;
                   }
                   return 0;
          break;
        
        default:
          
          // Unknown::unknown(([], {}))
          std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
          break;
        }
      
    case 0x13:
      switch (INTFUNC) {
        
        case 0x0:  
          // IntegerOperate::mull([' Rc_sl = Ra_sl * Rb_or_imm_sl; ', 'IntMultOp'],{})
          
           {
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new MullImm(machInst)
                         : (AlphaStaticInst *)new Mull(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x20:  
          // IntegerOperate::mulq([' Rc    = Ra    * Rb_or_imm;    ', 'IntMultOp'],{})
          
           {
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new MulqImm(machInst)
                         : (AlphaStaticInst *)new Mulq(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x30:  
          // IntegerOperate::umulh(['\n                uint64_t hi, lo;\n                mul128(Ra, Rb_or_imm, hi, lo);\n                Rc = hi;\n            ', 'IntMultOp'],{})
          
           {
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new UmulhImm(machInst)
                         : (AlphaStaticInst *)new Umulh(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x40:  
          // IntegerOperate::mullv(['\n                // 32-bit multiply with trap on overflow\n                int64_t Rax = Ra_sl;    // sign extended version of Ra_sl\n                int64_t Rbx = Rb_or_imm_sl;\n                int64_t tmp = Rax * Rbx;\n                // To avoid overflow, all the upper 32 bits must match\n                // the sign bit of the lower 32.  We code this as\n                // checking the upper 33 bits for all 0s or all 1s.\n                uint64_t sign_bits = tmp<63:31>;\n                if (sign_bits != 0 && sign_bits != mask(33))\n                    fault = new IntegerOverflowFault;\n                Rc_sl = tmp<31:0>;\n            ', 'IntMultOp'],{})
          
           {
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new MullvImm(machInst)
                         : (AlphaStaticInst *)new Mullv(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x60:  
          // IntegerOperate::mulqv(['\n                // 64-bit multiply with trap on overflow\n                uint64_t hi, lo;\n                mul128(Ra, Rb_or_imm, hi, lo);\n                // all the upper 64 bits must match the sign bit of\n                // the lower 64\n                if (!((hi == 0 && lo<63:> == 0) ||\n                      (hi == mask(64) && lo<63:> == 1)))\n                    fault = new IntegerOverflowFault;\n                Rc = lo;\n            ', 'IntMultOp'],{})
          
           {
               AlphaStaticInst *i =
                   (IMM) ? (AlphaStaticInst *)new MulqvImm(machInst)
                         : (AlphaStaticInst *)new Mulqv(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        default:
          
          // Unknown::unknown(([], {}))
          std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
          break;
        }
      
    case 0x1c:
      switch (INTFUNC) {
        
        case 0x0:
          switch (RA) {
            
            case 0x1f:  
              // IntegerOperate::sextb([' Rc_sb = Rb_or_imm< 7:0>; '],{})
              
               {
                   AlphaStaticInst *i =
                       (IMM) ? (AlphaStaticInst *)new SextbImm(machInst)
                             : (AlphaStaticInst *)new Sextb(machInst);
                   if (RC == 31) {
                       i = makeNop(i);
                   }
                   return i;
               }
              break;
            
            default:
              
              // Unknown::unknown(([], {}))
              std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
              break;
            }
          
        case 0x1:
          switch (RA) {
            
            case 0x1f:  
              // IntegerOperate::sextw([' Rc_sw = Rb_or_imm<15:0>; '],{})
              
               {
                   AlphaStaticInst *i =
                       (IMM) ? (AlphaStaticInst *)new SextwImm(machInst)
                             : (AlphaStaticInst *)new Sextw(machInst);
                   if (RC == 31) {
                       i = makeNop(i);
                   }
                   return i;
               }
              break;
            
            default:
              
              // Unknown::unknown(([], {}))
              std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
              break;
            }
          
        case 0x30:  
          // IntegerOperate::ctpop(['\n                             uint64_t count = 0;\n                             for (int i = 0; Rb<63:i>; ++i) {\n                                 if (Rb<i:i> == 0x1)\n                                     ++count;\n                             }\n                             Rc = count;\n                           ', 'IntAluOp'],{})
          
           {
               AlphaStaticInst *i = new Ctpop(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x31:  
          // IntegerOperate::perr(['\n                             uint64_t temp = 0;\n                             int hi = 7;\n                             int lo = 0;\n                             for (int i = 0; i < 8; ++i) {\n                                 uint8_t ra_ub = Ra_uq<hi:lo>;\n                                 uint8_t rb_ub = Rb_uq<hi:lo>;\n                                 temp += (ra_ub >= rb_ub) ? \n                                         (ra_ub - rb_ub) : (rb_ub - ra_ub);\n                                 hi += 8;\n                                 lo += 8;\n                             }\n                             Rc = temp;\n                           '],{})
          
           {
               AlphaStaticInst *i = new Perr(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x32:  
          // IntegerOperate::ctlz(['\n                             uint64_t count = 0;\n                             uint64_t temp = Rb;\n                             if (temp<63:32>) temp >>= 32; else count += 32;\n                             if (temp<31:16>) temp >>= 16; else count += 16;\n                             if (temp<15:8>) temp >>= 8; else count += 8;\n                             if (temp<7:4>) temp >>= 4; else count += 4;\n                             if (temp<3:2>) temp >>= 2; else count += 2;\n                             if (temp<1:1>) temp >>= 1; else count += 1;\n                             if ((temp<0:0>) != 0x1) count += 1;\n                             Rc = count;\n                           ', 'IntAluOp'],{})
          
           {
               AlphaStaticInst *i = new Ctlz(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x33:  
          // IntegerOperate::cttz(['\n                             uint64_t count = 0;\n                             uint64_t temp = Rb;\n                             if (!(temp<31:0>)) { temp >>= 32; count += 32; }\n                             if (!(temp<15:0>)) { temp >>= 16; count += 16; }\n                             if (!(temp<7:0>)) { temp >>= 8; count += 8; }\n                             if (!(temp<3:0>)) { temp >>= 4; count += 4; }\n                             if (!(temp<1:0>)) { temp >>= 2; count += 2; }\n                             if (!(temp<0:0> & ULL(0x1))) { \n                                 temp >>= 1; count += 1; \n                             }\n                             if (!(temp<0:0> & ULL(0x1))) count += 1;\n                             Rc = count;\n                           ', 'IntAluOp'],{})
          
           {
               AlphaStaticInst *i = new Cttz(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x34:  
          // IntegerOperate::unpkbw([' \n                             Rc = (Rb_uq<7:0>\n                                   | (Rb_uq<15:8> << 16)\n                                   | (Rb_uq<23:16> << 32)\n                                   | (Rb_uq<31:24> << 48));\n                           ', 'IntAluOp'],{})
          
           {
               AlphaStaticInst *i = new Unpkbw(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x35:  
          // IntegerOperate::unpkbl(['\n                             Rc = (Rb_uq<7:0> | (Rb_uq<15:8> << 32));\n                           ', 'IntAluOp'],{})
          
           {
               AlphaStaticInst *i = new Unpkbl(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x36:  
          // IntegerOperate::pkwb(['\n                             Rc = (Rb_uq<7:0>\n                                   | (Rb_uq<23:16> << 8)\n                                   | (Rb_uq<39:32> << 16)\n                                   | (Rb_uq<55:48> << 24));\n                           ', 'IntAluOp'],{})
          
           {
               AlphaStaticInst *i = new Pkwb(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x37:  
          // IntegerOperate::pklb(['\n                             Rc = (Rb_uq<7:0> | (Rb_uq<39:32> << 8));\n                           ', 'IntAluOp'],{})
          
           {
               AlphaStaticInst *i = new Pklb(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x38:  
          // IntegerOperate::minsb8(['\n                             uint64_t temp = 0;\n                             int hi = 63;\n                             int lo = 56;\n                             for (int i = 7; i >= 0; --i) {\n                                 int8_t ra_sb = Ra_uq<hi:lo>;\n                                 int8_t rb_sb = Rb_uq<hi:lo>;\n                                 temp = ((temp << 8) \n                                         | ((ra_sb < rb_sb) ? Ra_uq<hi:lo>\n                                                          : Rb_uq<hi:lo>));\n                                 hi -= 8;\n                                 lo -= 8;\n                             }\n                             Rc = temp;\n                          '],{})
          
           {
               AlphaStaticInst *i = new Minsb8(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x39:  
          // IntegerOperate::minsw4(['\n                             uint64_t temp = 0;\n                             int hi = 63;\n                             int lo = 48;\n                             for (int i = 3; i >= 0; --i) {\n                                 int16_t ra_sw = Ra_uq<hi:lo>;\n                                 int16_t rb_sw = Rb_uq<hi:lo>;\n                                 temp = ((temp << 16) \n                                         | ((ra_sw < rb_sw) ? Ra_uq<hi:lo>\n                                                          : Rb_uq<hi:lo>));\n                                 hi -= 16;\n                                 lo -= 16;\n                             }\n                             Rc = temp;\n                          '],{})
          
           {
               AlphaStaticInst *i = new Minsw4(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x3a:  
          // IntegerOperate::minub8(['\n                             uint64_t temp = 0;\n                             int hi = 63;\n                             int lo = 56;\n                             for (int i = 7; i >= 0; --i) {\n                                 uint8_t ra_ub = Ra_uq<hi:lo>;\n                                 uint8_t rb_ub = Rb_uq<hi:lo>;\n                                 temp = ((temp << 8) \n                                         | ((ra_ub < rb_ub) ? Ra_uq<hi:lo>\n                                                          : Rb_uq<hi:lo>));\n                                 hi -= 8;\n                                 lo -= 8;\n                             }\n                             Rc = temp;\n                          '],{})
          
           {
               AlphaStaticInst *i = new Minub8(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x3b:  
          // IntegerOperate::minuw4(['\n                             uint64_t temp = 0;\n                             int hi = 63;\n                             int lo = 48;\n                             for (int i = 3; i >= 0; --i) {\n                                 uint16_t ra_sw = Ra_uq<hi:lo>;\n                                 uint16_t rb_sw = Rb_uq<hi:lo>;\n                                 temp = ((temp << 16) \n                                         | ((ra_sw < rb_sw) ? Ra_uq<hi:lo>\n                                                          : Rb_uq<hi:lo>));\n                                 hi -= 16;\n                                 lo -= 16;\n                             }\n                             Rc = temp;\n                          '],{})
          
           {
               AlphaStaticInst *i = new Minuw4(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x3c:  
          // IntegerOperate::maxub8(['\n                             uint64_t temp = 0;\n                             int hi = 63;\n                             int lo = 56;\n                             for (int i = 7; i >= 0; --i) {\n                                 uint8_t ra_ub = Ra_uq<hi:lo>;\n                                 uint8_t rb_ub = Rb_uq<hi:lo>;\n                                 temp = ((temp << 8) \n                                         | ((ra_ub > rb_ub) ? Ra_uq<hi:lo>\n                                                          : Rb_uq<hi:lo>));\n                                 hi -= 8;\n                                 lo -= 8;\n                             }\n                             Rc = temp;\n                          '],{})
          
           {
               AlphaStaticInst *i = new Maxub8(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x3d:  
          // IntegerOperate::maxuw4(['\n                             uint64_t temp = 0;\n                             int hi = 63;\n                             int lo = 48;\n                             for (int i = 3; i >= 0; --i) {\n                                 uint16_t ra_uw = Ra_uq<hi:lo>;\n                                 uint16_t rb_uw = Rb_uq<hi:lo>;\n                                 temp = ((temp << 16) \n                                         | ((ra_uw > rb_uw) ? Ra_uq<hi:lo>\n                                                          : Rb_uq<hi:lo>));\n                                 hi -= 16;\n                                 lo -= 16;\n                             }\n                             Rc = temp;\n                          '],{})
          
           {
               AlphaStaticInst *i = new Maxuw4(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x3e:  
          // IntegerOperate::maxsb8(['\n                             uint64_t temp = 0;\n                             int hi = 63;\n                             int lo = 56;\n                             for (int i = 7; i >= 0; --i) {\n                                 int8_t ra_sb = Ra_uq<hi:lo>;\n                                 int8_t rb_sb = Rb_uq<hi:lo>;\n                                 temp = ((temp << 8) \n                                         | ((ra_sb > rb_sb) ? Ra_uq<hi:lo>\n                                                          : Rb_uq<hi:lo>));\n                                 hi -= 8;\n                                 lo -= 8;\n                             }\n                             Rc = temp;\n                          '],{})
          
           {
               AlphaStaticInst *i = new Maxsb8(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x3f:  
          // IntegerOperate::maxsw4(['\n                             uint64_t temp = 0;\n                             int hi = 63;\n                             int lo = 48;\n                             for (int i = 3; i >= 0; --i) {\n                                 int16_t ra_sw = Ra_uq<hi:lo>;\n                                 int16_t rb_sw = Rb_uq<hi:lo>;\n                                 temp = ((temp << 16) \n                                         | ((ra_sw > rb_sw) ? Ra_uq<hi:lo>\n                                                          : Rb_uq<hi:lo>));\n                                 hi -= 16;\n                                 lo -= 16;\n                             }\n                             Rc = temp;\n                          '],{})
          
           {
               AlphaStaticInst *i = new Maxsw4(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x70:
          switch (RB) {
            
            case 0x1f:  
              // BasicOperateWithNopCheck::ftoit([' Rc = Fa_uq; ', 'FloatCvtOp'],{})
              
               {
                   AlphaStaticInst *i = new Ftoit(machInst);
                   if (RC == 31) {
                       i = makeNop(i);
                   }
                   return i;
               }
              break;
            
            default:
              
              // Unknown::unknown(([], {}))
              std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
              break;
            }
          
        case 0x78:
          switch (RB) {
            
            case 0x1f:  
              // BasicOperateWithNopCheck::ftois([' Rc_sl = t_to_s(Fa_uq); ', 'FloatCvtOp'],{})
              
               {
                   AlphaStaticInst *i = new Ftois(machInst);
                   if (RC == 31) {
                       i = makeNop(i);
                   }
                   return i;
               }
              break;
            
            default:
              
              // Unknown::unknown(([], {}))
              std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
              break;
            }
          
        default:
          
          // Unknown::unknown(([], {}))
          std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
          break;
        }
      
    case 0x39:  
      // CondBranch::beq([' cond = (Ra == 0); '],{})
      
          std::cout << "beq" << std::endl; return 0; // Beq(machInst);
      break;
    
    case 0x3d:  
      // CondBranch::bne([' cond = (Ra != 0); '],{})
      
          std::cout << "bne" << std::endl; return 0; // Bne(machInst);
      break;
    
    case 0x3e:  
      // CondBranch::bge([' cond = (Ra_sq >= 0); '],{})
      
          std::cout << "bge" << std::endl; return 0; // Bge(machInst);
      break;
    
    case 0x3f:  
      // CondBranch::bgt([' cond = (Ra_sq >  0); '],{})
      
          std::cout << "bgt" << std::endl; return 0; // Bgt(machInst);
      break;
    
    case 0x3b:  
      // CondBranch::ble([' cond = (Ra_sq <= 0); '],{})
      
          std::cout << "ble" << std::endl; return 0; // Ble(machInst);
      break;
    
    case 0x3a:  
      // CondBranch::blt([' cond = (Ra_sq < 0); '],{})
      
          std::cout << "blt" << std::endl; return 0; // Blt(machInst);
      break;
    
    case 0x38:  
      // CondBranch::blbc([' cond = ((Ra & 1) == 0); '],{})
      
          std::cout << "blbc" << std::endl; return 0; // Blbc(machInst);
      break;
    
    case 0x3c:  
      // CondBranch::blbs([' cond = ((Ra & 1) == 1); '],{})
      
          std::cout << "blbs" << std::endl; return 0; // Blbs(machInst);
      break;
    
    case 0x31:  
      // CondBranch::fbeq([' cond = (Fa == 0); '],{})
      
          std::cout << "fbeq" << std::endl; return 0; // Fbeq(machInst);
      break;
    
    case 0x35:  
      // CondBranch::fbne([' cond = (Fa != 0); '],{})
      
          std::cout << "fbne" << std::endl; return 0; // Fbne(machInst);
      break;
    
    case 0x36:  
      // CondBranch::fbge([' cond = (Fa >= 0); '],{})
      
          std::cout << "fbge" << std::endl; return 0; // Fbge(machInst);
      break;
    
    case 0x37:  
      // CondBranch::fbgt([' cond = (Fa >  0); '],{})
      
          std::cout << "fbgt" << std::endl; return 0; // Fbgt(machInst);
      break;
    
    case 0x33:  
      // CondBranch::fble([' cond = (Fa <= 0); '],{})
      
          std::cout << "fble" << std::endl; return 0; // Fble(machInst);
      break;
    
    case 0x32:  
      // CondBranch::fblt([' cond = (Fa < 0); '],{})
      
          std::cout << "fblt" << std::endl; return 0; // Fblt(machInst);
      break;
    
    case 0x30:  
      // UncondBranch::br([],{})
      
          return (RA == 31)
              ? (StaticInst *)new Br(machInst)
              : (StaticInst *)new BrAndLink(machInst);
      break;
    
    case 0x34:  
      // UncondBranch::bsr(['IsCall'],{})
      
          return (RA == 31)
              ? (StaticInst *)new Bsr(machInst)
              : (StaticInst *)new BsrAndLink(machInst);
      break;
    
    case 0x1a:
      switch (JMPFUNC) {
        
        case 0x0:  
          // Jump::jmp([],{})
          
              return (RA == 31)
                  ? (StaticInst *)new Jmp(machInst)
                  : (StaticInst *)new JmpAndLink(machInst);
          break;
        
        case 0x1:  
          // Jump::jsr(['IsCall'],{})
          
              return (RA == 31)
                  ? (StaticInst *)new Jsr(machInst)
                  : (StaticInst *)new JsrAndLink(machInst);
          break;
        
        case 0x2:  
          // Jump::ret(['IsReturn'],{})
          
              return (RA == 31)
                  ? (StaticInst *)new Ret(machInst)
                  : (StaticInst *)new RetAndLink(machInst);
          break;
        
        case 0x3:  
          // Jump::jsr_coroutine(['IsCall', 'IsReturn'],{})
          
              return (RA == 31)
                  ? (StaticInst *)new Jsr_coroutine(machInst)
                  : (StaticInst *)new Jsr_coroutineAndLink(machInst);
          break;
        
        default:
          
          // Unknown::unknown(([], {}))
          std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
          break;
        }
      
    case 0x14:
      switch (FP_SHORTFUNC) {
        
        case 0x4:
          switch (RB) {
            
            case 0x1f:
              switch (FP_FULLFUNC) {
                
                case 0x4:  
                  // BasicOperateWithNopCheck::itofs([' Fc_uq = s_to_t(Ra_ul); ', 'FloatCvtOp'],{})
                  
                   {
                       AlphaStaticInst *i = new Itofs(machInst);
                       if (RC == 31) {
                           i = makeNop(i);
                       }
                       return i;
                   }
                  break;
                
                case 0x24:  
                  // BasicOperateWithNopCheck::itoft([' Fc_uq = Ra_uq; ', 'FloatCvtOp'],{})
                  
                   {
                       AlphaStaticInst *i = new Itoft(machInst);
                       if (RC == 31) {
                           i = makeNop(i);
                       }
                       return i;
                   }
                  break;
                
                case 0x14:  
                  // FailUnimpl::itoff(([], {}))
                  
                      std::cout << "itoff" << std::endl; return 0; // FailUnimplemented("itoff", machInst);
                  break;
                
                default:
                  
                  // Unknown::unknown(([], {}))
                  std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
                  break;
                }
              
            default:
              
              // Unknown::unknown(([], {}))
              std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
              break;
            }
          
        case 0xb:
          switch (FA) {
            
            case 0x1f:
              switch (FP_TYPEFUNC) {
#if SS_COMPATIBLE_FP
                
                case 0xb:  
                  // FloatingPointOperate::sqrts(['\n                        if (Fb < 0.0)\n                            fault = new ArithmeticFault;\n                        Fc = sqrt(Fb);\n                    ', 'FloatSqrtOp'],{})
                  
                   {
                       AlphaStaticInst *i = new Sqrts(machInst);
                       if (FC == 31) {
                           i = makeNop(i);
                       }
                       return i;
                   }
                  break;
#else
                
                case 0xb:  
                  // FloatingPointOperate::sqrts(['\n                        if (Fb_sf < 0.0)\n                            fault = new ArithmeticFault;\n                        Fc_sf = sqrt(Fb_sf);\n                    ', 'FloatSqrtOp'],{})
                  
                   {
                       AlphaStaticInst *i = new Sqrts(machInst);
                       if (FC == 31) {
                           i = makeNop(i);
                       }
                       return i;
                   }
                  break;
#endif
                
                case 0x2b:  
                  // FloatingPointOperate::sqrtt(['\n                        if (Fb < 0.0)\n                            fault = new ArithmeticFault;\n                        Fc = sqrt(Fb);\n                    ', 'FloatSqrtOp'],{})
                  
                   {
                       AlphaStaticInst *i = new Sqrtt(machInst);
                       if (FC == 31) {
                           i = makeNop(i);
                       }
                       return i;
                   }
                  break;
                
                default:
                  
                  // Unknown::unknown(([], {}))
                  std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
                  break;
                }
              
            default:
              
              // Unknown::unknown(([], {}))
              std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
              break;
            }
          
        case 0xa:  
          // FailUnimpl::sqrtfg(([], {}))
          
              std::cout << "sqrtfg" << std::endl; return 0; // FailUnimplemented("sqrtfg", machInst);
          break;
        
        default:
          
          // Unknown::unknown(([], {}))
          std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
          break;
        }
      
    case 0x16:
      switch (FP_SHORTFUNC_TOP2) {
        
        case 0x0:
          switch (FP_TRAPMODE) {
            
            case 0x0: case 0x1: case 0x5: case 0x7:
              switch (FP_TYPEFUNC) {
#if SS_COMPATIBLE_FP
                
                case 0x0:  
                  // FloatingPointOperate::adds([' Fc = Fa + Fb; '],{})
                  
                   {
                       AlphaStaticInst *i = new Adds(machInst);
                       if (FC == 31) {
                           i = makeNop(i);
                       }
                       return i;
                   }
                  break;
                
                case 0x1:  
                  // FloatingPointOperate::subs([' Fc = Fa - Fb; '],{})
                  
                   {
                       AlphaStaticInst *i = new Subs(machInst);
                       if (FC == 31) {
                           i = makeNop(i);
                       }
                       return i;
                   }
                  break;
                
                case 0x2:  
                  // FloatingPointOperate::muls([' Fc = Fa * Fb; ', 'FloatMultOp'],{})
                  
                   {
                       AlphaStaticInst *i = new Muls(machInst);
                       if (FC == 31) {
                           i = makeNop(i);
                       }
                       return i;
                   }
                  break;
                
                case 0x3:  
                  // FloatingPointOperate::divs([' Fc = Fa / Fb; ', 'FloatDivOp'],{})
                  
                   {
                       AlphaStaticInst *i = new Divs(machInst);
                       if (FC == 31) {
                           i = makeNop(i);
                       }
                       return i;
                   }
                  break;
#else
                
                case 0x0:  
                  // FloatingPointOperate::adds([' Fc_sf = Fa_sf + Fb_sf; '],{})
                  
                   {
                       AlphaStaticInst *i = new Adds(machInst);
                       if (FC == 31) {
                           i = makeNop(i);
                       }
                       return i;
                   }
                  break;
                
                case 0x1:  
                  // FloatingPointOperate::subs([' Fc_sf = Fa_sf - Fb_sf; '],{})
                  
                   {
                       AlphaStaticInst *i = new Subs(machInst);
                       if (FC == 31) {
                           i = makeNop(i);
                       }
                       return i;
                   }
                  break;
                
                case 0x2:  
                  // FloatingPointOperate::muls([' Fc_sf = Fa_sf * Fb_sf; ', 'FloatMultOp'],{})
                  
                   {
                       AlphaStaticInst *i = new Muls(machInst);
                       if (FC == 31) {
                           i = makeNop(i);
                       }
                       return i;
                   }
                  break;
                
                case 0x3:  
                  // FloatingPointOperate::divs([' Fc_sf = Fa_sf / Fb_sf; ', 'FloatDivOp'],{})
                  
                   {
                       AlphaStaticInst *i = new Divs(machInst);
                       if (FC == 31) {
                           i = makeNop(i);
                       }
                       return i;
                   }
                  break;
#endif
                
                case 0x20:  
                  // FloatingPointOperate::addt([' Fc = Fa + Fb; '],{})
                  
                   {
                       AlphaStaticInst *i = new Addt(machInst);
                       if (FC == 31) {
                           i = makeNop(i);
                       }
                       return i;
                   }
                  break;
                
                case 0x21:  
                  // FloatingPointOperate::subt([' Fc = Fa - Fb; '],{})
                  
                   {
                       AlphaStaticInst *i = new Subt(machInst);
                       if (FC == 31) {
                           i = makeNop(i);
                       }
                       return i;
                   }
                  break;
                
                case 0x22:  
                  // FloatingPointOperate::mult([' Fc = Fa * Fb; ', 'FloatMultOp'],{})
                  
                   {
                       AlphaStaticInst *i = new Mult(machInst);
                       if (FC == 31) {
                           i = makeNop(i);
                       }
                       return i;
                   }
                  break;
                
                case 0x23:  
                  // FloatingPointOperate::divt([' Fc = Fa / Fb; ', 'FloatDivOp'],{})
                  
                   {
                       AlphaStaticInst *i = new Divt(machInst);
                       if (FC == 31) {
                           i = makeNop(i);
                       }
                       return i;
                   }
                  break;
                
                default:
                  
                  // Unknown::unknown(([], {}))
                  std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
                  break;
                }
              
            default:
              
              // Unknown::unknown(([], {}))
              std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
              break;
            }
          
        case 0x1:
          switch (FP_FULLFUNC) {
            
            case 0xa5: case 0x5a5:  
              // BasicOperateWithNopCheck::cmpteq([' Fc = (Fa == Fb) ? 2.0 : 0.0; ', 'FloatCmpOp'],{})
              
               {
                   AlphaStaticInst *i = new Cmpteq(machInst);
                   if (RC == 31) {
                       i = makeNop(i);
                   }
                   return i;
               }
              break;
            
            case 0xa7: case 0x5a7:  
              // BasicOperateWithNopCheck::cmptle([' Fc = (Fa <= Fb) ? 2.0 : 0.0; ', 'FloatCmpOp'],{})
              
               {
                   AlphaStaticInst *i = new Cmptle(machInst);
                   if (RC == 31) {
                       i = makeNop(i);
                   }
                   return i;
               }
              break;
            
            case 0xa6: case 0x5a6:  
              // BasicOperateWithNopCheck::cmptlt([' Fc = (Fa <  Fb) ? 2.0 : 0.0; ', 'FloatCmpOp'],{})
              
               {
                   AlphaStaticInst *i = new Cmptlt(machInst);
                   if (RC == 31) {
                       i = makeNop(i);
                   }
                   return i;
               }
              break;
            
            case 0xa4: case 0x5a4:  
              // BasicOperateWithNopCheck::cmptun([' // unordered\n                    Fc = (!(Fa < Fb) && !(Fa == Fb) && !(Fa > Fb)) ? 2.0 : 0.0;\n                ', 'FloatCmpOp'],{})
              
               {
                   AlphaStaticInst *i = new Cmptun(machInst);
                   if (RC == 31) {
                       i = makeNop(i);
                   }
                   return i;
               }
              break;
            
            default:
              
              // Unknown::unknown(([], {}))
              std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
              break;
            }
          
        case 0x3:
          switch (FA) {
            
            case 0x1f:
              switch (FP_TYPEFUNC) {
                
                case 0x2f:
                  switch (FP_ROUNDMODE) {
                    
                    case 0x0:  
                      // FPFixedRounding::cvttq([' Fc_sq = (int64_t)trunc(Fb); ', 'Chopped'],{})
                      
                       {
                           AlphaStaticInst *i = new CvttqChopped(machInst);
                           if (FC == 31) {
                               i = makeNop(i);
                           }
                           return i;
                       }
                      break;
                    
                    case 0x1:  
                      // FPFixedRounding::cvttq([' Fc_sq = (int64_t)floor(Fb); ', 'MinusInfinity'],{})
                      
                       {
                           AlphaStaticInst *i = new CvttqMinusInfinity(machInst);
                           if (FC == 31) {
                               i = makeNop(i);
                           }
                           return i;
                       }
                      break;
                    
                    default:  
                      // FloatingPointOperate::cvttq([' Fc_sq = (int64_t)nearbyint(Fb); '],{})
                      
                       {
                           AlphaStaticInst *i = new Cvttq(machInst);
                           if (FC == 31) {
                               i = makeNop(i);
                           }
                           return i;
                       }
                      break;
                    }
                  
                case 0x2c:
                  switch (FP_FULLFUNC) {
                    
                    case 0x2ac: case 0x6ac:  
                      // BasicOperateWithNopCheck::cvtst([' Fc = Fb_sf; '],{})
                      
                       {
                           AlphaStaticInst *i = new Cvtst(machInst);
                           if (RC == 31) {
                               i = makeNop(i);
                           }
                           return i;
                       }
                      break;
                    
                    default:  
                      // FloatingPointOperate::cvtts([' Fc_sf = Fb; '],{})
                      
                       {
                           AlphaStaticInst *i = new Cvtts(machInst);
                           if (FC == 31) {
                               i = makeNop(i);
                           }
                           return i;
                       }
                      break;
                    }
                  
                case 0x3c:
                  switch (FP_TRAPMODE) {
                    
                    case 0x0: case 0x7:  
                      // FloatingPointOperate::cvtqs([' Fc_sf = Fb_sq; '],{})
                      
                       {
                           AlphaStaticInst *i = new Cvtqs(machInst);
                           if (FC == 31) {
                               i = makeNop(i);
                           }
                           return i;
                       }
                      break;
                    
                    default:
                      
                      // Unknown::unknown(([], {}))
                      std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
                      break;
                    }
                  
                case 0x3e:
                  switch (FP_TRAPMODE) {
                    
                    case 0x0: case 0x7:  
                      // FloatingPointOperate::cvtqt([' Fc    = Fb_sq; '],{})
                      
                       {
                           AlphaStaticInst *i = new Cvtqt(machInst);
                           if (FC == 31) {
                               i = makeNop(i);
                           }
                           return i;
                       }
                      break;
                    
                    default:
                      
                      // Unknown::unknown(([], {}))
                      std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
                      break;
                    }
                  
                default:
                  
                  // Unknown::unknown(([], {}))
                  std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
                  break;
                }
              
            default:
              
              // Unknown::unknown(([], {}))
              std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
              break;
            }
          
        default:
          
          // Unknown::unknown(([], {}))
          std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
          break;
        }
      
    case 0x17:
      switch (FP_FULLFUNC) {
        
        case 0x10:  
          // BasicOperateWithNopCheck::cvtlq(['\n                Fc_sl = (Fb_uq<63:62> << 30) | Fb_uq<58:29>;\n            '],{})
          
           {
               AlphaStaticInst *i = new Cvtlq(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x30:  
          // BasicOperateWithNopCheck::cvtql(['\n                Fc_uq = (Fb_uq<31:30> << 62) | (Fb_uq<29:0> << 29);\n            '],{})
          
           {
               AlphaStaticInst *i = new Cvtql(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x130: case 0x530:  
          // BasicOperateWithNopCheck::cvtqlv(['\n                // To avoid overflow, all the upper 32 bits must match\n                // the sign bit of the lower 32.  We code this as\n                // checking the upper 33 bits for all 0s or all 1s.\n                uint64_t sign_bits = Fb_uq<63:31>;\n                if (sign_bits != 0 && sign_bits != mask(33))\n                    fault = new IntegerOverflowFault;\n                Fc_uq = (Fb_uq<31:30> << 62) | (Fb_uq<29:0> << 29);\n            '],{})
          
           {
               AlphaStaticInst *i = new Cvtqlv(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x20:  
          // BasicOperateWithNopCheck::cpys(['  // copy sign\n                Fc_uq = (Fa_uq<63:> << 63) | Fb_uq<62:0>;\n            '],{})
          
           {
               AlphaStaticInst *i = new Cpys(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x21:  
          // BasicOperateWithNopCheck::cpysn([' // copy sign negated\n                Fc_uq = (~Fa_uq<63:> << 63) | Fb_uq<62:0>;\n            '],{})
          
           {
               AlphaStaticInst *i = new Cpysn(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x22:  
          // BasicOperateWithNopCheck::cpyse([' // copy sign and exponent\n                Fc_uq = (Fa_uq<63:52> << 52) | Fb_uq<51:0>;\n            '],{})
          
           {
               AlphaStaticInst *i = new Cpyse(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x2a:  
          // BasicOperateWithNopCheck::fcmoveq([' Fc = (Fa == 0) ? Fb : Fc; '],{})
          
           {
               AlphaStaticInst *i = new Fcmoveq(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x2b:  
          // BasicOperateWithNopCheck::fcmovne([' Fc = (Fa != 0) ? Fb : Fc; '],{})
          
           {
               AlphaStaticInst *i = new Fcmovne(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x2c:  
          // BasicOperateWithNopCheck::fcmovlt([' Fc = (Fa <  0) ? Fb : Fc; '],{})
          
           {
               AlphaStaticInst *i = new Fcmovlt(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x2d:  
          // BasicOperateWithNopCheck::fcmovge([' Fc = (Fa >= 0) ? Fb : Fc; '],{})
          
           {
               AlphaStaticInst *i = new Fcmovge(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x2e:  
          // BasicOperateWithNopCheck::fcmovle([' Fc = (Fa <= 0) ? Fb : Fc; '],{})
          
           {
               AlphaStaticInst *i = new Fcmovle(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x2f:  
          // BasicOperateWithNopCheck::fcmovgt([' Fc = (Fa >  0) ? Fb : Fc; '],{})
          
           {
               AlphaStaticInst *i = new Fcmovgt(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x24:  
          // BasicOperateWithNopCheck::mt_fpcr([' FPCR = Fa_uq; ', 'IsIprAccess'],{})
          
           {
               AlphaStaticInst *i = new Mt_fpcr(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        case 0x25:  
          // BasicOperateWithNopCheck::mf_fpcr([' Fa_uq = FPCR; ', 'IsIprAccess'],{})
          
           {
               AlphaStaticInst *i = new Mf_fpcr(machInst);
               if (RC == 31) {
                   i = makeNop(i);
               }
               return i;
           }
          break;
        
        default:
          
          // Unknown::unknown(([], {}))
          std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
          break;
        }
      
    case 0x18:
      switch (MEMFUNC) {
        
        case 0x8000:  
          // WarnUnimpl::fetch([],{})
          
              std::cout << "fetch" << std::endl; return 0; // WarnUnimplemented("fetch", machInst);
          break;
        
        case 0xa000:  
          // WarnUnimpl::fetch_m([],{})
          
              std::cout << "fetch_m" << std::endl; return 0; // WarnUnimplemented("fetch_m", machInst);
          break;
        
        case 0xe800:  
          // WarnUnimpl::ecb([],{})
          
              std::cout << "ecb" << std::endl; return 0; // WarnUnimplemented("ecb", machInst);
          break;
        
        case 0xf800:  
          // MiscPrefetch::wh64([' EA = Rb & ~ULL(63); ', ' ; '],{'mem_flags': 'PREFETCH'})
          
              std::cout << "wh64" << std::endl; return 0; // Wh64(machInst);
          break;
        
        case 0xc000:  
          // BasicOperate::rpcc(['\n                /* Rb is a fake dependency so here is a fun way to get\n                 * the parser to understand that.\n                 */\n                uint64_t unused_var M5_VAR_USED = Rb;\n                Ra = FullSystem ? xc->readMiscReg(IPR_CC) : curTick();\n            ', 'IsUnverifiable'],{})
          
              std::cout << "rpcc" << std::endl; return 0; // Rpcc(machInst);
          break;
        
        case 0x0:  
          // BasicOperate::trapb([' ', 'IsSerializing', 'IsSerializeBefore', 'No_OpClass'],{})
          
              std::cout << "trapb" << std::endl; return 0; // Trapb(machInst);
          break;
        
        case 0x400:  
          // BasicOperate::excb([' ', 'IsSerializing', 'IsSerializeBefore', 'No_OpClass'],{})
          
              std::cout << "excb" << std::endl; return 0; // Excb(machInst);
          break;
        
        case 0x4000:  
          // BasicOperate::mb([' ', 'IsMemBarrier', 'MemReadOp'],{})
          
              std::cout << "mb" << std::endl; return 0; // Mb(machInst);
          break;
        
        case 0x4400:  
          // BasicOperate::wmb([' ', 'IsWriteBarrier', 'MemWriteOp'],{})
          
              std::cout << "wmb" << std::endl; return 0; // Wmb(machInst);
          break;
        
        case 0xe000:
          switch (FullSystemInt) {
            
            case 0x0:  
              // FailUnimpl::rc_se(([], {}))
              
                  std::cout << "rc_se" << std::endl; return 0; // FailUnimplemented("rc_se", machInst);
              break;
            
            default:  
              // BasicOperate::rc((['\n                Ra = IntrFlag;\n                IntrFlag = 0;\n            ', 'IsNonSpeculative', 'IsUnverifiable'], {}))
              
                  std::cout << "rc" << std::endl; return 0; // Rc(machInst);
              break;
            }
          
        case 0xf000:
          switch (FullSystemInt) {
            
            case 0x0:  
              // FailUnimpl::rs_se(([], {}))
              
                  std::cout << "rs_se" << std::endl; return 0; // FailUnimplemented("rs_se", machInst);
              break;
            
            default:  
              // BasicOperate::rs((['\n                Ra = IntrFlag;\n                IntrFlag = 1;\n            ', 'IsNonSpeculative', 'IsUnverifiable'], {}))
              
                  std::cout << "rs" << std::endl; return 0; // Rs(machInst);
              break;
            }
          
        default:
          
          // Unknown::unknown(([], {}))
          std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
          break;
        }
      
    case 0x0:
      switch (FullSystemInt) {
        
        case 0x0:
          switch (PALFUNC) {
            
            case 0x0:  
              // EmulatedCallPal::halt(['\n                    exitSimLoop("halt instruction encountered");\n                ', 'IsNonSpeculative'],{})
              
                  std::cout << "halt" << std::endl; return 0; // Halt(machInst);
              break;
            
            case 0x83:  
              // EmulatedCallPal::callsys(['\n                    xc->syscall(R0);\n                ', 'IsSerializeAfter', 'IsNonSpeculative', 'IsSyscall'],{})
              
                  std::cout << "callsys" << std::endl; return 0; // Callsys(machInst);
              break;
            
            case 0x9e:  
              // EmulatedCallPal::rduniq([' R0 = Runiq; ', 'IsIprAccess'],{})
              
                  std::cout << "rduniq" << std::endl; return 0; // Rduniq(machInst);
              break;
            
            case 0x9f:  
              // EmulatedCallPal::wruniq([' Runiq = R16; ', 'IsIprAccess'],{})
              
                  std::cout << "wruniq" << std::endl; return 0; // Wruniq(machInst);
              break;
            
            default:
              
              // Unknown::unknown(([], {}))
              std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
              break;
            }
          
        default:  
          // CallPal::call_pal((['\n            if (!palValid ||\n                (palPriv\n                 && xc->readMiscReg(IPR_ICM) != mode_kernel)) {\n                // invalid pal function code, or attempt to do privileged\n                // PAL call in non-kernel mode\n                fault = new UnimplementedOpcodeFault;\n            } else {\n                // check to see if simulator wants to do something special\n                // on this PAL call (including maybe suppress it)\n                bool dopal = xc->simPalCheck(palFunc);\n\n                if (dopal) {\n                    xc->setMiscReg(IPR_EXC_ADDR, NPC);\n                    NPC = xc->readMiscReg(IPR_PAL_BASE) + palOffset;\n                }\n            }\n        ', 'IsNonSpeculative'], {}))
          
              std::cout << "call_pal" << std::endl; return 0; // Call_pal(machInst);
          break;
        }
      
    case 0x1b:
      switch (PALMODE) {
        
        case 0x0:  
          // OpcdecFault::hw_st_quad(([], {}))
          std::cout << "opcdecfault" << std::endl; return 0; // OpcdecFault(machInst);
          break;
        
        case 0x1:
          switch (HW_LDST_QUAD) {
            
            case 0x0:  
              // HwLoad::hw_ld([' EA = (Rb + disp) & ~3; ', ' Ra = Mem_ul; ', 'L', 'IsSerializing', 'IsSerializeBefore'],{})
              
                  std::cout << "hw_ldl" << std::endl; return 0; // Hw_ldL(machInst);
              break;
            
            case 0x1:  
              // HwLoad::hw_ld([' EA = (Rb + disp) & ~7; ', ' Ra = Mem_uq; ', 'Q', 'IsSerializing', 'IsSerializeBefore'],{})
              
                  std::cout << "hw_ldq" << std::endl; return 0; // Hw_ldQ(machInst);
              break;
            
            default:
              
              // Unknown::unknown(([], {}))
              std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
              break;
            }
          
        default:
          
          // Unknown::unknown(([], {}))
          std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
          break;
        }
      
    case 0x1f:
      switch (PALMODE) {
        
        case 0x0:  
          // OpcdecFault::hw_st_cond(([], {}))
          std::cout << "opcdecfault" << std::endl; return 0; // OpcdecFault(machInst);
          break;
        
        case 0x1:
          switch (HW_LDST_COND) {
            
            case 0x0:
              switch (HW_LDST_QUAD) {
                
                case 0x0:  
                  // HwStore::hw_st([' EA = (Rb + disp) & ~3; ', ' Mem_ul = Ra<31:0>; ', 'L', 'IsSerializing', 'IsSerializeBefore'],{})
                  
                      std::cout << "hw_stl" << std::endl; return 0; // Hw_stL(machInst);
                  break;
                
                case 0x1:  
                  // HwStore::hw_st([' EA = (Rb + disp) & ~7; ', ' Mem_uq = Ra_uq; ', 'Q', 'IsSerializing', 'IsSerializeBefore'],{})
                  
                      std::cout << "hw_stq" << std::endl; return 0; // Hw_stQ(machInst);
                  break;
                
                default:
                  
                  // Unknown::unknown(([], {}))
                  std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
                  break;
                }
              
            case 0x1:  
              // FailUnimpl::hw_st_cond(([], {}))
              
                  std::cout << "hw_st_cond" << std::endl; return 0; // FailUnimplemented("hw_st_cond", machInst);
              break;
            
            default:
              
              // Unknown::unknown(([], {}))
              std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
              break;
            }
          
        default:
          
          // Unknown::unknown(([], {}))
          std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
          break;
        }
      
    case 0x19:
      switch (PALMODE) {
        
        case 0x0:  
          // OpcdecFault::hw_mfpr(([], {}))
          std::cout << "opcdecfault" << std::endl; return 0; // OpcdecFault(machInst);
          break;
        
        case 0x1:  
          // HwMoveIPR::hw_mfpr(['\n                int miscRegIndex = (ipr_index < MaxInternalProcRegs) ?\n                        IprToMiscRegIndex[ipr_index] : -1;\n                if(miscRegIndex < 0 || !IprIsReadable(miscRegIndex) ||\n                    miscRegIndex >= NumInternalProcRegs)\n                        fault = new UnimplementedOpcodeFault;\n                else\n                    Ra = xc->readMiscReg(miscRegIndex);\n            ', 'IsIprAccess'],{})
          
              std::cout << "hw_mfpr" << std::endl; return 0; // Hw_mfpr(machInst);
          break;
        
        default:
          
          // Unknown::unknown(([], {}))
          std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
          break;
        }
      
    case 0x1d:
      switch (PALMODE) {
        
        case 0x0:  
          // OpcdecFault::hw_mtpr(([], {}))
          std::cout << "opcdecfault" << std::endl; return 0; // OpcdecFault(machInst);
          break;
        
        case 0x1:  
          // HwMoveIPR::hw_mtpr(['\n                int miscRegIndex = (ipr_index < MaxInternalProcRegs) ?\n                        IprToMiscRegIndex[ipr_index] : -1;\n                if(miscRegIndex < 0 || !IprIsWritable(miscRegIndex) ||\n                    miscRegIndex >= NumInternalProcRegs)\n                        fault = new UnimplementedOpcodeFault;\n                else\n                    xc->setMiscReg(miscRegIndex, Ra);\n                if (traceData) { traceData->setData(Ra); }\n            ', 'IsIprAccess'],{})
          
              std::cout << "hw_mtpr" << std::endl; return 0; // Hw_mtpr(machInst);
          break;
        
        default:
          
          // Unknown::unknown(([], {}))
          std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
          break;
        }
      
    case 0x1e:
      switch (PALMODE) {
        
        case 0x0:  
          // OpcdecFault::hw_rei(([], {}))
          std::cout << "opcdecfault" << std::endl; return 0; // OpcdecFault(machInst);
          break;
        
        case 0x1:  
          // BasicOperate::hw_rei([' xc->hwrei(); ', 'IsSerializing', 'IsSerializeBefore'],{})
          
              std::cout << "hw_rei" << std::endl; return 0; // Hw_rei(machInst);
          break;
        
        default:
          
          // Unknown::unknown(([], {}))
          std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
          break;
        }
      
    case 0x1:
      switch (M5FUNC) {
        
        case 0x0:  
          // BasicOperate::arm(['\n                PseudoInst::arm(xc->tcBase());\n            ', 'IsNonSpeculative'],{})
          
              std::cout << "arm" << std::endl; return 0; // Arm(machInst);
          break;
        
        case 0x1:  
          // BasicOperate::quiesce(["\n                // Don't sleep if (unmasked) interrupts are pending\n                Interrupts* interrupts =\n                    xc->tcBase()->getCpuPtr()->getInterruptController();\n                if (interrupts->checkInterrupts(xc->tcBase())) {\n                    PseudoInst::quiesceSkip(xc->tcBase());\n                } else {\n                    PseudoInst::quiesce(xc->tcBase());\n                }\n            ", 'IsNonSpeculative', 'IsQuiesce'],{})
          
              std::cout << "quiesce" << std::endl; return 0; // Quiesce(machInst);
          break;
        
        case 0x2:  
          // BasicOperate::quiesceNs(['\n                PseudoInst::quiesceNs(xc->tcBase(), R16);\n            ', 'IsNonSpeculative', 'IsQuiesce'],{})
          
              std::cout << "quiescens" << std::endl; return 0; // QuiesceNs(machInst);
          break;
        
        case 0x3:  
          // BasicOperate::quiesceCycles(['\n                PseudoInst::quiesceCycles(xc->tcBase(), R16);\n            ', 'IsNonSpeculative', 'IsQuiesce', 'IsUnverifiable'],{})
          
              std::cout << "quiescecycles" << std::endl; return 0; // QuiesceCycles(machInst);
          break;
        
        case 0x4:  
          // BasicOperate::quiesceTime(['\n                R0 = PseudoInst::quiesceTime(xc->tcBase());\n            ', 'IsNonSpeculative', 'IsUnverifiable'],{})
          
              std::cout << "quiescetime" << std::endl; return 0; // QuiesceTime(machInst);
          break;
        
        case 0x7:  
          // BasicOperate::rpns(['\n                R0 = PseudoInst::rpns(xc->tcBase());\n            ', 'IsNonSpeculative', 'IsUnverifiable'],{})
          
              std::cout << "rpns" << std::endl; return 0; // Rpns(machInst);
          break;
        
        case 0x9:  
          // BasicOperate::wakeCPU(['\n                PseudoInst::wakeCPU(xc->tcBase(), R16);\n            ', 'IsNonSpeculative', 'IsUnverifiable'],{})
          
              std::cout << "wakecpu" << std::endl; return 0; // WakeCPU(machInst);
          break;
        
        case 0x10:  
          // BasicOperate::deprecated_ivlb(['\n                warn_once("Obsolete M5 ivlb instruction encountered.\\n");\n            '],{})
          
              std::cout << "deprecated_ivlb" << std::endl; return 0; // Deprecated_ivlb(machInst);
          break;
        
        case 0x11:  
          // BasicOperate::deprecated_ivle(['\n                warn_once("Obsolete M5 ivlb instruction encountered.\\n");\n            '],{})
          
              std::cout << "deprecated_ivle" << std::endl; return 0; // Deprecated_ivle(machInst);
          break;
        
        case 0x20:  
          // BasicOperate::deprecated_exit(['\n                warn_once("deprecated M5 exit instruction encountered.\\n");\n                PseudoInst::m5exit(xc->tcBase(), 0);\n            ', 'No_OpClass', 'IsNonSpeculative'],{})
          
              std::cout << "deprecated_exit" << std::endl; return 0; // Deprecated_exit(machInst);
          break;
        
        case 0x21:  
          // BasicOperate::m5exit(['\n                PseudoInst::m5exit(xc->tcBase(), R16);\n            ', 'No_OpClass', 'IsNonSpeculative'],{})
          
              std::cout << "m5exit" << std::endl; return 0; // M5exit(machInst);
          break;
        
        case 0x31:  
          // BasicOperate::loadsymbol(['\n                PseudoInst::loadsymbol(xc->tcBase());\n            ', 'No_OpClass', 'IsNonSpeculative'],{})
          
              std::cout << "loadsymbol" << std::endl; return 0; // Loadsymbol(machInst);
          break;
        
        case 0x30:  
          // BasicOperate::initparam(['\n                Ra = PseudoInst::initParam(xc->tcBase());\n            '],{})
          
              std::cout << "initparam" << std::endl; return 0; // Initparam(machInst);
          break;
        
        case 0x40:  
          // BasicOperate::resetstats(['\n                PseudoInst::resetstats(xc->tcBase(), R16, R17);\n            ', 'IsNonSpeculative'],{})
          
              std::cout << "resetstats" << std::endl; return 0; // Resetstats(machInst);
          break;
        
        case 0x41:  
          // BasicOperate::dumpstats(['\n                PseudoInst::dumpstats(xc->tcBase(), R16, R17);\n            ', 'IsNonSpeculative'],{})
          
              std::cout << "dumpstats" << std::endl; return 0; // Dumpstats(machInst);
          break;
        
        case 0x42:  
          // BasicOperate::dumpresetstats(['\n                PseudoInst::dumpresetstats(xc->tcBase(), R16, R17);\n            ', 'IsNonSpeculative'],{})
          
              std::cout << "dumpresetstats" << std::endl; return 0; // Dumpresetstats(machInst);
          break;
        
        case 0x43:  
          // BasicOperate::m5checkpoint(['\n                PseudoInst::m5checkpoint(xc->tcBase(), R16, R17);\n            ', 'IsNonSpeculative'],{})
          
              std::cout << "m5checkpoint" << std::endl; return 0; // M5checkpoint(machInst);
          break;
        
        case 0x50:  
          // BasicOperate::m5readfile(['\n                R0 = PseudoInst::readfile(xc->tcBase(), R16, R17, R18);\n            ', 'IsNonSpeculative'],{})
          
              std::cout << "m5readfile" << std::endl; return 0; // M5readfile(machInst);
          break;
        
        case 0x51:  
          // BasicOperate::m5break(['\n                PseudoInst::debugbreak(xc->tcBase());\n            ', 'IsNonSpeculative'],{})
          
              std::cout << "m5break" << std::endl; return 0; // M5break(machInst);
          break;
        
        case 0x52:  
          // BasicOperate::m5switchcpu(['\n                PseudoInst::switchcpu(xc->tcBase());\n            ', 'IsNonSpeculative'],{})
          
              std::cout << "m5switchcpu" << std::endl; return 0; // M5switchcpu(machInst);
          break;
        
        case 0x53:  
          // BasicOperate::m5addsymbol(['\n                PseudoInst::addsymbol(xc->tcBase(), R16, R17);\n            ', 'IsNonSpeculative'],{})
          
              std::cout << "m5addsymbol" << std::endl; return 0; // M5addsymbol(machInst);
          break;
        
        case 0x54:  
          // BasicOperate::m5panic(['\n                panic("M5 panic instruction called at pc = %#x.", PC);\n            ', 'IsNonSpeculative'],{})
          
              std::cout << "m5panic" << std::endl; return 0; // M5panic(machInst);
          break;
#define  CPANN(lbl) CPA::cpa()->lbl(xc->tcBase())
        
        case 0x55:
          switch (RA) {
            
            case 0x0:  
              // BasicOperate::m5a_old(['\n                    panic("Deprecated M5 annotate instruction executed "\n                          "at pc = %#x\\n", PC);\n                ', 'IsNonSpeculative'],{})
              
                  std::cout << "m5a_old" << std::endl; return 0; // M5a_old(machInst);
              break;
            
            case 0x1:  
              // BasicOperate::m5a_bsm(['\n                    CPANN(swSmBegin);\n                ', 'IsNonSpeculative'],{})
              
                  std::cout << "m5a_bsm" << std::endl; return 0; // M5a_bsm(machInst);
              break;
            
            case 0x2:  
              // BasicOperate::m5a_esm(['\n                    CPANN(swSmEnd);\n                ', 'IsNonSpeculative'],{})
              
                  std::cout << "m5a_esm" << std::endl; return 0; // M5a_esm(machInst);
              break;
            
            case 0x3:  
              // BasicOperate::m5a_begin(['\n                    CPANN(swExplictBegin);\n                ', 'IsNonSpeculative'],{})
              
                  std::cout << "m5a_begin" << std::endl; return 0; // M5a_begin(machInst);
              break;
            
            case 0x4:  
              // BasicOperate::m5a_end(['\n                    CPANN(swEnd);\n                ', 'IsNonSpeculative'],{})
              
                  std::cout << "m5a_end" << std::endl; return 0; // M5a_end(machInst);
              break;
            
            case 0x6:  
              // BasicOperate::m5a_q(['\n                    CPANN(swQ);\n                ', 'IsNonSpeculative'],{})
              
                  std::cout << "m5a_q" << std::endl; return 0; // M5a_q(machInst);
              break;
            
            case 0x7:  
              // BasicOperate::m5a_dq(['\n                    CPANN(swDq);\n                ', 'IsNonSpeculative'],{})
              
                  std::cout << "m5a_dq" << std::endl; return 0; // M5a_dq(machInst);
              break;
            
            case 0x8:  
              // BasicOperate::m5a_wf(['\n                    CPANN(swWf);\n                ', 'IsNonSpeculative'],{})
              
                  std::cout << "m5a_wf" << std::endl; return 0; // M5a_wf(machInst);
              break;
            
            case 0x9:  
              // BasicOperate::m5a_we(['\n                    CPANN(swWe);\n                ', 'IsNonSpeculative'],{})
              
                  std::cout << "m5a_we" << std::endl; return 0; // M5a_we(machInst);
              break;
            
            case 0xc:  
              // BasicOperate::m5a_sq(['\n                    CPANN(swSq);\n                ', 'IsNonSpeculative'],{})
              
                  std::cout << "m5a_sq" << std::endl; return 0; // M5a_sq(machInst);
              break;
            
            case 0xd:  
              // BasicOperate::m5a_aq(['\n                    CPANN(swAq);\n                ', 'IsNonSpeculative'],{})
              
                  std::cout << "m5a_aq" << std::endl; return 0; // M5a_aq(machInst);
              break;
            
            case 0xe:  
              // BasicOperate::m5a_pq(['\n                    CPANN(swPq);\n                ', 'IsNonSpeculative'],{})
              
                  std::cout << "m5a_pq" << std::endl; return 0; // M5a_pq(machInst);
              break;
            
            case 0xf:  
              // BasicOperate::m5a_l(['\n                    CPANN(swLink);\n                ', 'IsNonSpeculative'],{})
              
                  std::cout << "m5a_l" << std::endl; return 0; // M5a_l(machInst);
              break;
            
            case 0x10:  
              // BasicOperate::m5a_identify(['\n                    CPANN(swIdentify);\n                ', 'IsNonSpeculative'],{})
              
                  std::cout << "m5a_identify" << std::endl; return 0; // M5a_identify(machInst);
              break;
            
            case 0x11:  
              // BasicOperate::m5a_getid(['\n                    R0 = CPANN(swGetId);\n                ', 'IsNonSpeculative'],{})
              
                  std::cout << "m5a_getid" << std::endl; return 0; // M5a_getid(machInst);
              break;
            
            case 0x13:  
              // BasicOperate::m5a_scl(['\n                    CPANN(swSyscallLink);\n                ', 'IsNonSpeculative'],{})
              
                  std::cout << "m5a_scl" << std::endl; return 0; // M5a_scl(machInst);
              break;
            
            case 0x14:  
              // BasicOperate::m5a_rq(['\n                    CPANN(swRq);\n                ', 'IsNonSpeculative'],{})
              
                  std::cout << "m5a_rq" << std::endl; return 0; // M5a_rq(machInst);
              break;
            
            default:
              
              // Unknown::unknown(([], {}))
              std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
              break;
            }
          #undef CPANN
        
        case 0x56:  
          // BasicOperate::m5reserved2(['\n                warn("M5 reserved opcode ignored");\n            ', 'IsNonSpeculative'],{})
          
              std::cout << "UNKNOWN" << std::endl; return 1; // M5reserved2(machInst);
          break;
        
        case 0x57:  
          // BasicOperate::m5reserved3(['\n                warn("M5 reserved opcode ignored");\n            ', 'IsNonSpeculative'],{})
          
              std::cout << "UNKNOWN" << std::endl; return 1; // M5reserved3(machInst);
          break;
        
        case 0x58:  
          // BasicOperate::m5reserved4(['\n                warn("M5 reserved opcode ignored");\n            ', 'IsNonSpeculative'],{})
          
              std::cout << "UNKNOWN" << std::endl; return 1; // M5reserved4(machInst);
          break;
        
        case 0x59:  
          // BasicOperate::m5reserved5(['\n                warn("M5 reserved opcode ignored");\n            ', 'IsNonSpeculative'],{})
          
              std::cout << "UNKNOWN" << std::endl; return 1; // M5reserved5(machInst);
          break;
        
        default:
          
          // Unknown::unknown(([], {}))
          std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
          break;
        }
      
    default:
      
      // Unknown::unknown(([], {}))
      std::cout << "UNKNOWN" << std::endl; return 1; // Unknown(machInst);
      break;
    }
  }
