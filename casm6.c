// This is the first line of this program
// changing lcasm4.c to casm5.c to casm6.c
// partial replacement of 32-bit Linux studio.h
 typedef struct _IO_FILE __FILE;
 typedef struct _IO_FILE FILE;
 #define SEEK_SET 0
 #define SEEK_END 2
 extern struct _IO_FILE *stdin;
 extern struct _IO_FILE *stdout;
 extern int fread(char*,long,long,FILE *fr);
 extern int fwrite(char*,long,long,FILE *fw);
 extern FILE* fopen(char*,char*);
 extern int fclose(FILE*);
 extern void fseek(FILE*,long,int);
 extern long ftell(FILE*);
 extern void exit(int);
// This lcasm4.c 8086 assembler program
// copyright C 2012 by Eric Matteson
// Permission is granted to copy this lcasm4.c
// source code file and to publish it on the
// Internet and to use it at least for
// non-profit use.
// This program has a history of
// starting out as a 8086 assembler with
// integer instructions only with bits 16
// . Later this program was upgraded by
// adding in a bits 32 addressing mode that
// inserts a sib byte when trying to use
// esp as base and 32 bit register orders are
// used for addressing when bits 32 is used.
// No warranty.
// This has been partially tested by assembling
// a small number of programs.
// No command line argument.
// lcasm4 will prompt for the source file
// name.asm
// and then later ask for the output file name
// on a later line.
// To compile on Linux use
// gcc -o lcasm4.out lcasm4.c
// 1020 REM lcasm4.txt from
// casm2.txt from basm2.txt
// 1030 REM remember to vote
// against reinstating the U.S. military draft .
// 1031 REM free assembler program LCASM4.C
//  by eric Matteson
//  #include<stdio.h>
// ------------------
  long slc,ddimed,dqval,dnbase;
  long ddigit,wdigit,dlren;
  long incstep,swbig,swtiny;
  long linepat,mdpat,lc,dfrac;
  long dnumer,denom,drer,dprod;
  long fp04,fl06;
// ------------------
     long ile429,iri429;
// ------------------
  long a80w,rep0,hv0c,eofi;
  long botdummy,phasecor;
  long alignctr,arcsymlen;
  long alignwarn,aagctr,wdarcsel;
  long irem16,irem8;
  long bigsymlim;
  long lrepeat,btwofour,validc;
  long aclen,acsub,acsuc,acsud;
  long acsue,brbase,brloc,brsub;
  long lastpos,lasttype,xrbase;
  long otherop,dlbase,iml,imh,imzf;
  long tcmpval,rtlim,rtsub,rrcmp;
  long tidget,rbase,regindex,regnumber;
  long regtype,regbase,mduuuram;
  long xxregxxx,emw,emd,emsize;
  long offsetloc,segerror;
  long pegindex,atwofour,notfound;
  long sybase,syepos,syfpos,errorlin;
  long crash,sln,pass,igto,igti;
  long rchosen,topen,eoft;
  long rsub,tclose,curtype,dlptr,imhh;
  long imhhh,mrl,mrr,mrc,mrui,mrsub;
  long mrchk,prvchr,symvalid,symbtype;
  long tidgit,rh1672,rreglen,lregbase;
  long rilop,cregchr,rregchr,tregchr;
  long loregchr,xybase,xychr,onereg;
  long harbase,harbw,nonreg,pregtype;
  long ssdexbas,poindex;
  long z514,hlrbw,qteepvar;
  long lslen,stpos,stlen,lsptr;
  long lschra,lschka,overwrt,lschrb;
  long sylenb,sycpos,lschrc,sychrc;
  long sychre,sichre;
  long symg,symknown,istlbase,cpuinlen;
  long isttype,resblen,istlen;
  long searlim,ibasesub,instchr,tabilen;
  long tabictr,rinstchr,labelen;
  long ihctr,igtix,compos,comctr;
  long vv,lefnib,atype,calpos,cachk;
  long dacd,cdtype,cdlen,bucd;
  long cdg,wrdis,afill,diffbot;
  long eofdelay,alignzur;
  long prntemp,bprntemp,washere;
  long aerrorln;
  long iirtarg;
// ----------------
     char *elevrd;
// ----------------
  FILE* hvruthie;
  FILE* hvpete;
// ------------------
     char clef428;
// -----------------
  char one2;
  char curchr,rrcmpc,rreglec;
  char imhc,imlc,imhhc,imhhhc;
  char chctarg;
// ------
  char u[]= " 0 1 2 3 DQ RESQ DD RESD "
  " DB DW RESB RESW ORG STAC"
   "KEND STACKORG NEGORG "
// 2300 REM compiler directives two jumps
   " ADD OR ADC SBB AND SUB XOR CMP "
// 2304 REM 2302 imed 100000dw mduuuram%+8*irem8%
// non imed uses 0+8*erem8%
// 2306 REM 2308 MOV imed c6+emw% md000r/m,
// 88+2*emd%+emw% seg, 8c+emd*2
    " MOV y y y y y y 31 "
    " PUSH y y y y y y 39 "
// 2312 REM PUSH 1010reg lastpos=32, word
// ff md 110 r/m  segment*8+6
    " POP y y y y y y 47 "
// 2316 REM pop 1011reg lastpos%=32,word
// 8f md000r/m,7+seg*8 (NOT CS)
  " INC DEC y y y y y y y y y y y y y 63 "
//  2320 REM 2318 irem8%*8+40h+reg
// lastpos%=32,byte fe+emw% md(emw%*8)R/M
// 2322 REM 2324 GOTO ON CONDITION
// USES irem16% instead of irem8%
  " JV JNV JB  JNB JE  JNE JBE JNBE "
  "  JS  JNS JPE JPO JL  JNL JNG  JNLE "
  " JO JNO JNAE JAE JZ JNZ JNA JA   "
  "  JN  JNN JP  JNP JNGE JGE JLE JG   "
// 2332 REM SEG OVERRIDE =26+8*segreg
  " ES CS SS DS y y y 103 "
  " RET  RETF y y y y y 111 "
// 2338 REM 2336 c2+8*irem8%,
// (add 1 if lasttype%<>1 not imed
  " ROL ROR RCL RCR SHL SHR 118 SAR "
  " ROL ROR RCL RCR SAL SHR 126 SAR "
// 2344 REM 2340 shifts d0+v*2+emw%
// MD(8*irem8%)R/M lasttype%=1 for v=0
  " LEA y y y y y y 135 "
// 2348 REM LEA 8D MDREGR/M
// 2350 REM 2352 single byte
// instructions 9c+irem8%*1
  " PUSHF POPF SAHF LAHF y y y 143 "
// REM call 2358 imed linepat&=4G211
// call far 9a(5) linepat&=4G22 rel e8(3)
// 56 REM mduuuram%<256 (xrbase-16)="F"
// far or near indirect  jmp same rules
  " CALL y y y y y y 151 "
  " JMP   y y y y y y 159 "
// 2362 REM 2364 TEST IMED f6+emw%
// md000r/m, 84+emw% MDREGR/M
  " TEST y y y y y y 167 "
// 2366 REM 2368 IN E4 + erem8%*1 + emw%,
// add 8 IF not imed
  " IN y OUT y y y y 175 "
//  2370 REM  2372 CE + irem8%*1
  " INTO IRET y y y y y 183 "
// 2374 REM 2376 CD+immediate
//  needs immediate number byte
  " INT y y y y y y 191 "
// 2378 REM 2380 single byte
// character series a4+irem16%
  " MOVSB MOVSW CMPSB CMPSW y 1"
  "97 STOSB STOSW "
  " LODSB LODSW SCASB SC"
  "ASW y y y 207       "
// 2384 REM 2386 F6 + emw%,C0+irem8%*8
// regsingle or irem8%*8+mduuuram%
  " y y NOT NEG y y y 215 "
// 2388 REM 2390 NOP 90
  " NOP y y y y y y 223 "
// 2392 REM 2394 loopne series
// realative jump E0+erem8%*1
  " LOOPNE LOOPE LOOP JCXZ y y y 231 "
// 2396 REM 2398 LES C4+irem8%*1,
// mduuuram%+xxregxxx%
  " LES LDS y y y y y 239 "
// 2400 REM 2402 lock series
// F0+irem8%*1 single byte
  " LOCK y REPNZ REPZ HALT CMC y 247 "
// 2404 REM 2406 duplicate lock series for REP
  " LOCK y REPNZ REP  HALT CMC y 255 "
// 2408 REM 2410 CLC SERIES
// F8+irem8%*1 single byte instructions
  " CLC STC CLI STI CLD STD y 263 "
// 2412 REM 2414 F6+emw%,mduuuram%+irem8%*8
  " 264 y y 267 MUL IMUL DIV IDIV "
// 2416 REM 2418 XCHG 86+emw%,mduuuram%+xxregxxx%
  " xchg y y y y y y 279 "
// 2420 REM 2422 27+irem8%*8 unknown byte group
  " DAA DAS AAA AAS y y y 287 "
// 2426 REM 2428 D4+irem8%*1
// unknown immediate8 group
  " AAM AAD y y y y y 295 "
// 2430 REM 2432 xlatb d7
  " XLATB y y y y y y 303 "
// 2434 REM 2436 cbw single byte
// series 98+irem8%*1
  " CBW CWD y WAIT y y y 311 "
  " BITS ALIGN SYMDIFF REALSE"
  "GDIFF SECTION y y 319 "
  " ..... ";
// 2438 REM end of known integer
// instruction list for 8088
// ----
  char listreg[] = "R0R1R2R3R4R5R6R7"
     "AXCXDXBXSPBPSIDI"
  "ALCLDLBLAHCHDHBHESCSSSDSRCRDRERF.......";
// arrays block top
  char comchr[1];
  char linesymms[1024];
  char mdregrtm[256];
  char acline[80];
  char rcmpval[80];
  char kbruthie[80];
  char fnruthie[80];
  char intruthie[80];
  char fnpete[80];
  int isthold[80];
  int fourbres[4];
  char bigsym[28671];
// arrays block bot              bot
// ----
  long sc(long,long,long);
  long iamfromc(char);
  char canminus(long);
  void rb1200();
  void rc1290();
  void rd1370();
  void re1460();
  void rf1540();
  void rg1560();
  void rh1650();
  void ri1690();
  void rj1760();
  void rku2150();
  void rk2170();
  void rl2171();
  void rm2274();
  void rn2278();
  void tj5040();
  void tj5148();
  void tj5149();
  void tj5166();
  void tj5170();
  void ag1620();
  void tg1630();
  void reedline();
  void readone();
  void scrprint(char*,long);
  void scrkey(char*);
  long hlong103(char*,long);
  long vlen103(char*,long);
  void fncopy260(char*,char*,long);
  void eebelcopy(char*,char*,long);
  long filtdiv(long,long);
  char jcfri(long);
  void jumbjrprn(char*,long,long,long);
  void bumbjrprn(char*,long,long,long,long);
  void openruth();
  long hlong101(char*);
// .... sc is subscript within bounds check
// for arrays and integer offsets
  long sc(long tyresub,long tyremax,long tyreln)
  {
  long tyrewub;
  tyrewub=tyremax-1;
  if(tyresub < 0)goto tyrefail39;
  if(tyresub >= tyremax)goto tyrefail39;
  tyrewub=tyresub;
  goto tyrebot41;
tyrefail39:  aerrorln=tyreln;
// insert debugger trigger
// crash in 32 bit mode here
tyrebot41:  if(tyresub<0)tyrewub=0;
  return tyrewub;
  }
  long iamfromc(char wasac)
  {
  long iumfromc;
  iumfromc=(long)wasac;
   if(iumfromc < 0)
   {
   iumfromc=iumfromc+256;
   }
  return iumfromc;
  }
  char canminus(long wasai)
  {
  char cbnminus;
  if(wasai < 128)cbnminus=(char)wasai;
  if(wasai > 127)cbnminus=(char)(wasai-256);
  return cbnminus;
  }
// -----
  void reedline()
  {
  long ctrd04;
  long ctra06;
  long ctrzz;
  long evdk;
  char bund;
  char rund;
// ***ERROR*** duplicate declaration
// of void readone();
  evdk=0;
  ctrd04=0;
  ctra06=0;
  ctrzz=0;
reedloop:  if(ctra06 < a80w)goto chkrep;
      goto afterloop;
chkrep:  if(rep0 != 0)goto crepeat;
      readone();
crepeat:  bund=one2;
      rep0 = 0;
cmpxc: rund = bund;
  if(bund == '\314')goto cmpxa;
  if(bund >= '\040')goto yreedu;
  rund = '\040';
  if(bund == '\015')goto cmpxd;
  if(bund == '\000')goto cmpxd;
  if(bund == '\012')goto cmpxa;
  if(bund == '\032')goto cmpxa;
// 015.001101.0d   032.011010.1a
// 012.001010.0a  314.11001100.cc
// 040.100000.20   176.1111110.7e
   *(elevrd + (sc(ctra06,80,208))) = rund;
    ctra06 ++;
    if(hv0c < 5)goto chkrev;
xreedj:  goto reedloop;
chkrev:  if(bund != '\10')goto xreedj;
      ctra06 -- ;
      if(ctra06 == 0)goto xreedj;
      ctra06 -- ;
      goto xreedj;
yreedu:  *(elevrd + (sc(ctra06,80,217)))=rund;
      ctra06 ++;
      goto reedloop;
cmpxd:  goto afterlined;
cmpxa:  goto afterlinea;
afterlined: goto afterlinea;
aftquit:  goto blanright;
afterlinea:  if(bund == '\012')goto aftquit;
             if(bund == '\032')goto aftquit;
      if(bund == '\314')goto aftquit;
dfirst:  if(hv0c >= 5)goto dseek;
      if((evdk % 2) == 0)goto dseek;
      goto aftquit;
dseek:  if(bund == '\015')goto dloopp;
      if(bund == '\000')goto dloopp;
      rep0 = 4;
      goto aftquit;
dloopp:  if(eofi == 0)goto dloop;
      goto aftquit;
dloop:  readone();
      bund=one2;
xtafterlinea:  ctrd04 ++ ;
      if(ctrd04 < 4)goto atafterlinea;
      if(bund == '\000')goto reefixdz;
      if(bund == '\015')goto reefixdz;
      goto atafterlinea;
reefixdz:  goto aftquit;
atafterlinea: goto afterlinea;
blanright:  ctrzz = ctra06;
blanlop:  if(ctra06 >= a80w)goto rpopline;
      *(elevrd + (sc(ctra06,80,247)))='\040';
      ctra06 ++ ;
      goto blanlop;
rpopline:  rund=rep0;
      goto reedret;
afterloop:  if(eofi == 0)goto alproca;
      goto aftquit;
alproca:  if (hv0c >=5)goto alprocb;
      goto aftquit;
alprocb:  readone();
      bund=one2;
      if(eofi == 0)goto rtafterlinea;
      ctrzz=8;
rtafterlinea:  goto  afterlinea;
reedret: ctrzz=0;
  }
   void readone()
      {
      char honeb;
      char* aoneb;
      aoneb = &honeb;
      if(fp04<fl06)goto keepreadone;
      honeb='\40';
      eofi=1;
      goto onedonecoth;
keepreadone:  fread(aoneb,1,1,hvruthie);
      fp04 ++;
      if(fp04 >= fl06)eofi=1;
onedonecoth: one2=honeb;
      }
  void scrprint(char* from260,long len260)
   {
   long prctr260;
   char oneh260;
   prctr260=0;
scrpr268: ile429=sc(prctr260,80,20268);
  oneh260 = *(from260 + ile429);
  prctr260=prctr260+1;
  ile429=1;
  if((len260 & 1) == 0)ile429=0;
  if(oneh260 != '\41')ile429=0;
  if(ile429 == 1)goto scrptr274;
  ile429=1;
  if((len260 & 1) == 0)ile429=0;
  if(oneh260 != '\56')ile429=0;
  if(ile429 == 1)goto scrptr274;
  if(oneh260 < '\40')oneh260 = '\56';
  fwrite(&oneh260,1,1,stdout);
  if(prctr260 < len260)goto scrpr268;
  if(len260 > 78)goto scrptr280;
scrptr274:  oneh260 = '\15';
  fwrite(&oneh260,1,1,stdout);
  oneh260 = '\12';
  fwrite(&oneh260,1,1,stdout);
scrptr280: prctr260=0;
  }
  void scrkey(char* kbuff260)
  {
  long skctr260,disallow260;
  char ky260,ky259;
  skctr260=0;
   while(skctr260 < 80)
   {
   *(kbuff260+(sc(skctr260,80,302))) = '\40';
   skctr260 ++;
   }
  skctr260=0;
   while(skctr260 < 80)
   {
   ky259 = '\40';
   disallow260 = 0;
   fread(&ky260,1,1,stdin);
   skctr260 ++;
   if((ky260 == '\15')||(ky260 == '\12'))
    {
    disallow260=1;
    skctr260=90;
    }
    if(ky260 == '\10')
    {
    disallow260=1;
    skctr260 --;
    if(skctr260 > 0)skctr260 --;
    }
    if(ky260 == '\11')disallow260=1;
  if(disallow260 == 0)
  {
  *(kbuff260+(sc((skctr260-1),80,324)))=ky260;
  }
// if(disallow260 == 0)scrprint(kbuff260,78);
    }
   }
   long hlong103(char* ptr103,long searlen103)
   {
   long hctr103,hset103,hallow103;
   char hcc103;
   hctr103=searlen103;
   hallow103=1;
    while((hctr103 > 0)&&(hallow103 > 0))
    {
    hset103=hctr103-1;
    ile429=sc(hset103,searlen103,20337);
    hcc103 = *(ptr103+ile429);
    hallow103=0;
    if(hcc103 == '\40')hallow103=1;
    if(hcc103 == '\0')hallow103=1;
    if(hallow103 > 0)hctr103=hset103;
    }
   return hctr103;
   }
   long vlen103(char* shorty103,long swid103)
   {
   long vctr103;
   char vchr103;
   vctr103=0;
voop103:  if(vctr103 >= swid103)goto vbot103;
  vchr103 = *(shorty103+(sc(vctr103,80,20352)));
  if(vchr103 == '\0')goto vbot103;
  if(vchr103 == '\40')goto vbot103;
  if(vchr103 == '\41')goto vbot103;
  if(vchr103 == '\56')goto vbot103;
  vctr103 = vctr103 + 1;
  goto voop103;
vbot103:  vchr103 = '\0';
  return vctr103;
  }
  void fncopy260(char* destfnz,
       char* srcfn,long cplen260)
   {
   long fnctra;
   fnctra=0;
    while(fnctra < cplen260)
    {
    clef428 = *(srcfn+(sc(fnctra,80,20351)));
    *(destfnz+(sc(fnctra,80,351)))=clef428;
    fnctra ++;
    }
   *(destfnz+(sc(cplen260,80,354))) = '\0';
   }
   void eebelcopy(char* desteb,
         char* srceb,long maxeeb)
   {
   long eebelctr;
   char eebchr;
   eebelctr=0;
    while(eebelctr < maxeeb)
    {
    *(desteb + (sc(eebelctr,80,363))) = '\40';
    eebelctr ++;
    }
   eebelctr=0;
    while(eebelctr < maxeeb)
    {
    eebchr = *(srceb+(sc(eebelctr,80,20369)));
    *(desteb + (sc(eebelctr,80,370)))=eebchr;
    eebelctr ++;
    if(eebchr == '\41')eebelctr=maxeeb+2;
    if(eebchr == '\56')eebelctr=maxeeb+2;
    }
   }
   long filtdiv(long filtop,long fildenom)
   {
   long filprod,filrem,filfrac;
   filfrac=filtop/fildenom;
   filprod=fildenom*filfrac;
   filrem=filtop-filprod;
   if(filrem < 0)filfrac=filfrac-1;
   return filfrac;
   }
  char jcfri(long ijar)
  {
  char jcres;
  jcres = 'j';
  if(ijar == 0)jcres = '0';
  if(ijar == 1)jcres = '1';
  if(ijar == 2)jcres = '2';
  if(ijar == 3)jcres = '3';
  if(ijar == 4)jcres = '4';
  if(ijar == 5)jcres = '5';
  if(ijar == 6)jcres = '6';
  if(ijar == 7)jcres = '7';
  if(ijar == 8)jcres = '8';
  if(ijar == 9)jcres = '9';
  if(ijar == 10)jcres = 'A';
  if(ijar == 11)jcres = 'B';
  if(ijar == 12)jcres = 'C';
  if(ijar == 13)jcres = 'D';
  if(ijar == 14)jcres = 'E';
  if(ijar == 15)jcres = 'F';
  return jcres;
  }
//     jumbjrprn is fixed base ten output
  void jumbjrprn(char* nbrdes,long jstpos,
                    long jswid,long jwvalue)
  {
  long jrbase,jrlgp,jrgffsdt;
  long jwshrink,jwdigitb,jwfrac,jwprod;
  char jcxcd;
  jrbase=5+5;
  jrlgp=jswid-1;
  jwshrink=jwvalue;
   while (jrlgp >= 0)
   {
   jwfrac=filtdiv(jwshrink,jrbase);
   jwprod=jwfrac*jrbase;
   jwdigitb=jwshrink-jwprod;
   jrgffsdt=jrlgp+jstpos-1;
   jcxcd=jcfri(jwdigitb);
   *(nbrdes+(sc(jrgffsdt,80,415)))=jcxcd;
   jwshrink=jwfrac;
   jrlgp --;
   }
  }
// bumjrprn is variable base output
  void bumbjrprn(char* inbrdes,long ijstpos,
         long ijswid,long sjwvalue,long ilsimb)
  {
  long ijrbase,ijrlgp,ijrgffsdt,ijwshrink;
  long ijwdigitb,ijwfrac,ijwprod,ijwvalue;
  int isneg;
  ijwvalue=sjwvalue;
  char ijcxcd;
  isneg=0;
  ijrbase=0;
  ijwshrink=1;
  if(sjwvalue < ijrbase)
  {
  ijwvalue=ijrbase-(sjwvalue+ijwshrink);
  isneg=1;
  }
  ijrbase=ilsimb;
  ijrlgp=ijswid-1;
  ijwshrink=ijwvalue;
   while (ijrlgp >= 0)
   {
   ijwfrac=filtdiv(ijwshrink,ijrbase);
   ijwprod=ijwfrac*ijrbase;
   ijwdigitb=ijwshrink-ijwprod;
   ijrgffsdt=ijrlgp+ijstpos-1;
   if(isneg == 0)ijcxcd=jcfri(ijwdigitb);
   if(isneg != 0)ijcxcd=jcfri((ijrbase-1)-ijwdigitb);
   *(inbrdes+(sc(ijrgffsdt,80,415)))=ijcxcd;
   ijwshrink=ijwfrac;
   ijrlgp --;
   }
  }
  void openruth()
   {
   char oru90[90];
   hvruthie=fopen(fnruthie,"rb");
// ------------------------------ 0609
   eebelcopy(oru90,"hvruthie=????????..!!",21);
   bumbjrprn(oru90,10,8,(long)hvruthie,16);
   scrprint(oru90,21);
   if(((long)hvruthie) == 0)
   {
   eebelcopy(oru90,"*** ERROR *** invalid hvruthie value..!!",40);
   scrprint(oru90,40);
   exit(0);
   }
// ------------------------------
   fseek(hvruthie,0,SEEK_END);
   fl06=ftell(hvruthie);
   fp04=0;
   fseek(hvruthie,0,SEEK_SET);
   eofi=0;
   eofdelay=0;
   rep0=0;
   hv0c=5;
   }
   long hlong101(char* biglist101)
   {
   long bigctr101,bigres101;
   char ccv101;
   ccv101='\40';
   bigres101=0;
   bigctr101=0;
   ile429=1;
   while(ile429 == 1)
    {
  ccv101= *(biglist101+(sc(bigctr101,4096,20440)));
      if((ccv101 != '\41')&&(ccv101 != '\56'))
      {
      bigctr101 ++;
      }
    if(ccv101 == '\41')ile429=0;
    if(ccv101 == '\56')ile429=0;
    if(bigctr101 >= 4096)ile429=0;
    }
  bigres101=bigctr101;
  return bigres101;
  }
// ---------
// 1196 REM curchr$ validc% linepat& mdpat&
// lrepeat%       btwofour%
// 1198 REM 1200 SUBROUTINE GETLINE
// 1199 REM  acline$ aclen% acsub% acsuc% acsud%
// acsue% brbase% brloc% brsub%
 void rb1200()
  {
zrb1200: acsub=0;
  eoft=0;
rb1202: linesymms[sc(acsub,1024,1202)] = '\0';
  acsub=acsub+1;
  if(acsub < 1024)goto rb1202;
  lrepeat=0;
  acsub=0;
rb1210: mdregrtm[sc(acsub,256,1210)] = '\0';
    acsub=acsub+1;
  if(acsub<256)goto rb1210;
rb1248: if(eofi != 0)goto rb1278;
rb1250: reedline();
  sln=sln+1;
  aclen=hlong103(elevrd,a80w);
  if(aclen<1)goto rb1248;
  brbase=0;
  acsue=0;
  acsub=0;
rb1262: acsub=acsub+1;
  curchr=acline[acsub-1];
  if(curchr=='\73')goto rb1272;
  acsue=acsue+1;
  if(acsue < aclen)goto rb1262;
rb1272: aclen=acsue;
  if(aclen < 1)goto rb1248;
  goto rb1281;
rb1278: eoft=1;
  aclen=0;
// zb1280 REM RETURN aclen% acline$ eoft%=0
rb1281: acsub=0;
// 1282 RETURN
  }
// 1288 REM rc1290 get character from acline$
   void rc1290()
  {
rrc1290: validc=1;
  curtype=0;
  if(lrepeat==0)goto rc1346;
// zc1294 REM RETURN validc% curchr$
// curtype% acsub%++
rc1296: if(curchr < 48)goto rc1304;
  if(curchr > 57)goto rc1304;
rc1300: curtype=1;
rc1302: goto rc1340;
//  1303 REM 0-9,A-H      ||||||||||||||||
// ||||||||||     I-Z
rc1304: if(curchr < 65) goto rc1307;
  if(curchr > 72) goto rc1307;
  goto rc1300;
rc1307: if(curchr > 104)goto rc1310;
  if(curchr < 97)goto rc1310;
  goto rc1300;
rc1310: if(curchr == 95)goto rc1320;
// zc1311 REM add alphabetic characters here
  if(curchr > 90)goto rc1318;
  if(curchr < 73)goto rc1318;
  goto rc1320;
rc1318: if(curchr > 122)goto rc1328;
  if(curchr < 105)goto rc1328;
rc1320: curtype=2;
// 1321 REM 105 i    122 z         104 h  97 a
  goto rc1302;
rc1324: curtype=3;
rc1326: goto rc1302;
// zc1327 REM blank []"+
rc1328: if(curchr==20)goto rc1326;
  if(curchr==91)goto rc1324;
  if(curchr==93)goto rc1324;
  if(curchr==34)goto rc1324;
  if(curchr==42)goto rc1324;
  if(curchr==43)goto rc1324;
  goto rc1326;
rc1340: lrepeat=0;
  goto rc1362;
rc1346: curchr=32;
  acsub=acsub+1;
  if(acsub > aclen)goto rc1354;
  goto rc1358;
rc1354: validc=0;
  goto rc1296;
rc1358: curchr=acline[sc((acsub-1),80,21358)];
  goto rc1296;
rc1362: botdummy=0;
    }
// 1368 REM 1370 get next symbol to linesymms
// 1369 REM symvalid% symbtype%
   void rd1370()
   {
rrd1370: symvalid=1;
  symbtype=0;
rd1372:  rc1290();
  if(validc==0)goto rd1416;
  if(curtype==0)goto rd1372;
  if(curtype==3)goto rd1418;
// zd1380 REM curtype%= 1 or 2
  if(acsub < 2)goto rd1394;
  brbase=brbase+arcsymlen+2;
  symbtype=0;
rd1394: brloc=2;
rd1396: brsub=brloc+brbase;
  brloc=brloc+1;
  linesymms[sc(brsub,1024,1396)]=curchr;
  if(curtype > symbtype)symbtype=curtype;
  prvchr=curchr;
  rc1290();
  if(brloc!=3)goto rd1408;
  if(prvchr<58)goto rd1408;
  symbtype=2;
// zd1407 REM first
// character <= 9 for symbtype == 1
rd1408: if(curtype==2)goto rd1396;
  if(curtype==1)goto rd1396;
  if(curtype < 3)goto rd1412;
  lrepeat=1;
rd1412: ile429=sc((brbase+1),1024,1412);
  linesymms[ile429]=(brloc-2);
  linesymms[sc(brbase,1024,1415)]=symbtype;
rd1415: goto rd1446;
rd1416: symvalid=0;
  goto rd1415;
rd1418: brbase=brbase+arcsymlen+2;
  if(curchr==34)goto rd1428;
  linesymms[sc(brbase,1024,1418)]=3;
  linesymms[sc((brbase+1),1024,1418)]=1;
  linesymms[sc((brbase+2),1024,1418)]=curchr;
  goto rd1415;
rd1428: brsub=brbase+2;
  linesymms[sc(brbase,1024,1428)]=2;
  brloc=0;
rd1432: rc1290();
  if(curchr==34)goto rd1444;
  linesymms[sc(brsub,1024,1432)]=curchr;
  brsub=brsub+1;
  brloc=brloc+1;
  goto rd1432;
rd1444: linesymms[sc((brbase+1),1024,1444)]=brloc;
rd1446: botdummy=0;
  }
// 1458 REM re1460 get group of symbols
// from already exsisting line
  void re1460()
  {
rre1460: brbase=0;
  regbase=0;
re1462: rd1370();
  if(symvalid==1)goto re1462;
  brbase=0;
  xrbase=0;
  otherop=0;
re1467: brbase=brbase+arcsymlen+2;
  mrchk=linesymms[sc(brbase,1024,21467)];
  if(mrchk==0)goto re1500;
  if(mrchk != 3)goto re1467;
  mrchk=linesymms[sc((brbase+2),1024,21467)];
  if(mrchk != 91)goto re1467;
  otherop=brbase-(arcsymlen+2);
  xrbase=brbase;
re1478: brbase=brbase+(arcsymlen+2);
re1479: mrsub=0;
re1483: mrui=linesymms[sc((brbase+2),1024,21483)];
  if(mrui==93)goto re1494;
re1485: mrl=mrsub+regbase;
  mrr=brbase+mrsub;
  mrc=linesymms[sc(mrr,1024,21485)];
  mdregrtm[sc(mrl,256,1485)]=mrc;
  mrsub=mrsub+1;
  if(mrsub<(arcsymlen+2))goto re1485;
  regbase=regbase+arcsymlen+2;
  goto re1478;
re1494: ile429=sc((brbase+arcsymlen+2),1024,21494);
  mrc=linesymms[ile429];
  if(xrbase==0)goto re1500;
  if(mrc==0)goto re1500;
  otherop=brbase+arcsymlen+2;
re1500: linepat=0;
  brbase=0;
  lasttype=0;
  lastpos=0;
re1505: brbase=brbase+arcsymlen+2;
  mrc=linesymms[sc(brbase,1024,21505)];
  if(mrc=='\0')goto re1516;
  lasttype=mrc;
  lastpos=brbase;
  if(brbase > ((arcsymlen+2)*7))goto re1515;
  if(xrbase != 0)goto re1515;
  linepat=linepat*4;
  linepat=linepat+lasttype;
re1515: goto re1505;
re1516: mdpat=0;
  regbase=0;
re1520: mrc=mdregrtm[sc(regbase,256,21520)];
  regbase=regbase+arcsymlen+2;
  if(mrc=='\0')goto re1530;
  mdpat=mdpat*4;
  mdpat=mdpat+mrc;
// ze1527 REM Also returns with lastpos%  lasttype%
  goto re1520;
// 1529 REM returns with xrbase% mdregrtm
// linesymms mdpat& linepat& otherop%
re1530: botdummy=0;
   }
// 1538 REM 1540 positive integer divide
//  drer&  dfrac&=dnumer&/denom&
   void rf1540()
   {
rrf1540: dfrac=dnumer/denom;
rf1542: dprod=dfrac*denom;
rf1544: drer=dnumer-dprod;
rf1546: if(drer<0)goto rf1550;
rf1548: goto rf1554;
rf1550: dfrac=dfrac-1;
rf1552: goto rf1542;
rf1554: botdummy=0;
  }
// 1557 REM rg1560 get iml%,imh%,ddimed&
//  imhh% imhhh% imzf%
// 1559 REM USING  dnbase&={16,10}
//  incoming dlbase%
  void rg1560()
  {
rrg1560: dlptr=dlbase+2;
  dnbase=16;
  dqval=0;
  ddimed=0;
rg1564: if(dlptr > 1023)goto rg1567;
  dlren=linesymms[sc(dlptr,1024,21564)];
  goto rg1568;
rg1567: dlren=mdregrtm[sc((dlptr-1024),256,21567)];
rg1568: dlptr=dlptr+1;
  wdigit=dlren;
  if(wdigit==72)goto rg1611;
  if(wdigit==104)goto rg1611;
  if(wdigit==103)goto rg1590;
  if(wdigit==71)goto rg1590;
  if(wdigit<65)goto rg1585;
  if(wdigit>70)goto rg1581;
  ddigit=(wdigit-65)+10;
rg1577: dqval=1;
rg1578: ddimed=ddimed*dnbase;
  ddimed=ddimed+ddigit;
  goto rg1564;
rg1581: if(wdigit<97)goto rg1610;
  if(wdigit>102)goto rg1610;
  ddigit=(wdigit-97)+10;
  goto rg1577;
rg1585: if(wdigit<48)goto rg1610;
  if(wdigit>57)goto rg1610;
  ddigit=wdigit-48;
  goto rg1578;
rg1590: dnbase=ddimed;
  ddimed=0;
rg1592: if(dlptr>1023)goto rg1595;
  dlren=linesymms[sc(dlptr,1024,21592)];
  goto rg1596;
rg1595: dlren=mdregrtm[sc((dlptr-1024),256,21595)];
rg1596: dlptr=dlptr+1;
  wdigit=dlren;
  if(wdigit<48)goto rg1611;
  if(wdigit>55)goto rg1611;
  ddigit=wdigit-48;
  ddimed=ddimed*dnbase;
  ddimed=ddimed+ddigit;
  goto rg1592;
rg1610: if(dqval==0)goto rg1612;
rg1611: goto rg1636;
rg1612: dlptr=dlbase+2;
  dnbase=10;
  ddimed=0;
rg1615: if(dlptr>1023)goto rg1618;
  dlren=linesymms[sc(dlptr,1024,21615)];
  goto rg1619;
rg1618: dlren=mdregrtm[sc((dlptr-1024),256,21618)];
rg1619: dlptr=dlptr+1;
  wdigit=dlren;
  if(wdigit<48)goto rg1611;
  if(wdigit>57)goto rg1611;
  ddigit=wdigit-48;
  ddimed=ddimed*dnbase;
  ddimed=ddimed+ddigit;
  goto rg1615;
// 1636 common
rg1636: dnumer=ddimed;
rg1646: ag1620();
rg1647: botdummy=0;
  }
  void ag1620()
  {
// ag1620 get iml imh imhh imhhh from signed ddimed
aag1620:  if(ddimed < 0)goto aag1623;
aag1621:  dnumer=ddimed;
aag1622:  goto aag1626;
aag1623:  dnumer=((0-1)-ddimed);
aag1626:  aagctr=0;
aag1628:  if(aagctr > 3)goto aag1637;
aag1629:  denom=256;
aag1630:  rf1540();
aag1631:  fourbres[aagctr]=255-drer;
aag1632:  if(ddimed < 0)goto aag1634;
aag1633:  fourbres[aagctr]=drer;
aag1634:  dnumer=dfrac;
aag1635:  aagctr=aagctr+1;
aag1636:  goto aag1628;
aag1637:  iml=fourbres[0];
aag1638:  imh=fourbres[1];
aag1639:  imhh=fourbres[2];
aag1640:  imhhh=fourbres[3];
  }
// bottom-----------------
  void tg1630()
  {
  ag1620();
  }
// 1648 REM rh1650 GET tcmpval% from rcmpval$
  void rh1650()
  {
rrh1650: rbase=16;
// rh1651: rtlim=hlong103(rcmpval,a80w);
// *** ERROR *** hlong103 is invalid method of
// checking this kind of string
rh1651: rtlim=vlen103(rcmpval,a80w);
  rtsub=0;
rh1653:  tcmpval=0;
rh1654: rtsub=rtsub+1;
  if(rtlim<rtsub)goto rh1684;
  rrcmpc=rcmpval[sc((rtsub-1),80,21654)];
  rrcmp=rrcmpc;
  if(rrcmp==(long)'H')goto rh1684;
  if(rrcmp==(long)'G')goto rh1680;
  if(rrcmpc<'A')goto rh1672;
  if(rrcmp>(long)'F')goto rh1684;
  tidgit=rrcmp-55;
rh1668: tcmpval=tcmpval*rbase;
  tcmpval=tcmpval+tidgit;
  goto rh1654;
rh1672: if(rrcmp<48)goto rh1684;
  if(rrcmp>57)goto rh1684;
  tidgit=rrcmp-48;
  goto rh1668;
rh1680: rbase=tcmpval;
rh1682: goto rh1653;
rh1684: botdummy=0;
  }
// 1686 REM ri1690 GET regindex% regnumber%
// regtype% FROM regbase%
   void ri1690()
   {
rri1690: if(regbase>1023)goto ri1696;
ri1692: ile429=sc((regbase+1),1024,21692);
  rreglec=linesymms[ile429];
  goto ri1698;
ri1696: ile429=sc(((regbase+1)-1024),256,21696);
  rreglec=mdregrtm[ile429];
ri1698: rreglen=rreglec;
  regnumber=0;
  regtype=1777;
  if(btwofour != 4)goto ri1703;
  if(rreglen==3)goto ri1707;
ri1703: if(rreglen==2)goto ri1707;
ri1704: regnumber=1777;
   regindex=1777;
  goto ri1756;
ri1707: goto ri1713;
ri1713: goto ri1716;
ri1714: regnumber=regnumber+1;
ri1716: lregbase=regnumber+regnumber+1;
  rilop=0;
ri1720: if(regbase>1023)goto ri1726;
ri1722: iri429=regbase+rilop+rreglen;
  ile429=sc(iri429,1024,21722);
  cregchr=linesymms[ile429];
  goto ri1728;
ri1726: ile429=rreglen+regbase+rilop-1024;
  cregchr=mdregrtm[sc(ile429,256,21726)];
ri1728: rregchr=cregchr;
  tregchr=listreg[sc((lregbase+rilop-1),68,21728)];
  loregchr=tregchr;
  if(loregchr==(long)('\41'))goto ri1704;
  if(loregchr==(long)('\56'))goto ri1704;
  if(rregchr<97)goto ri1740;
  if(rregchr>122)goto ri1740;
  loregchr=loregchr+32;
ri1740: rilop=rilop+1;
  if(loregchr != rregchr)goto ri1714;
  if(rilop<2)goto ri1720;
  denom=8;
  dnumer=regnumber;
  rf1540();
  regtype=dfrac;
  regindex=drer;
ri1756: botdummy=0;
 }
// 1758 REM rj1760 GET mduuuram%,
// xxregxxx%  emw% emd% emsize%
// 1759 REM offsetloc% segerror%
   void rj1760()
   {
rrj1760: mduuuram=1024;
  ssdexbas = 0;
  xxregxxx=1024;
  emw=1024;
  emd=1024;
rj1768: emsize=0;
  offsetloc=2048;
  segerror=0;
  if(xrbase != 0)goto rj1818;
// zj1776 REM unbracketed cases 1783 reg,
// imed      1798 reg,reg
  if(lasttype==2)goto rj1798;
  if(lasttype==1)goto rj1783;
// zj1781 REM 1789  1792.
// 1787.  is mduuuram% right register
rj1782: goto rj2066;
rj1783: regbase=lastpos-(arcsymlen+2);
rj1784: ri1690();
rj1785: if(regtype==1777)goto rj1782;
  if(segerror != 0)goto rj1794;
rj1787: if(regtype<3)goto rj1794;
  segerror=2;
rj1789: emd=0;
  xxregxxx=regindex*8;
  regindex=poindex;
rj1794: mduuuram=regindex+192;
  emw=2-regtype;
rj1796: emsize=1;
  goto rj1782;
rj1798: regbase=lastpos-(arcsymlen+2);
  ri1690();
  if(regtype==1777)goto rj1782;
  emd=1;
  if(regtype<3)goto rj1805;
  segerror=1;
  emd=1;
rj1805: xxregxxx=regindex*8;
  regbase=lastpos;
  pregtype=regtype;
  poindex=regindex;
  ri1690();
  if(regtype>2)goto rj1813;
  if(regindex==0)goto rj1813;
  regtype=pregtype;
rj1813: goto rj1785;
//  1814 REM BRACKETED [MDREGR/M]
// 1815 [],imed lasttype%=1 emw%width
// check linesymms(xrbase%-16+2)="B" or "b"
// REM reg,[] emd%=1 lasttype%=3
//     [] otherop% not register
// 1817 REM [],reg emd%=0 lasttype%=2
//       [] otherop% not register
rj1818: if(lasttype != 1)goto rj1836;
  xybase=xrbase-(arcsymlen+2);
  emw=1;
  xychr=linesymms[sc((xybase+2),1024,21818)];
  if(xychr==66)goto rj1830;
  if(xychr==98)goto rj1830;
  goto rj1834;
rj1830: emw=0;
rj1834: goto rj1884;
rj1836: regbase=otherop;
  ri1690();
   if(regtype==1777)goto rj1858;
  xxregxxx=regindex*8;
  emd=1;
  if(otherop<xrbase)goto rj1850;
  emd=0;
rj1850: emw=1;
  if(regtype<2)goto rj1858;
  if(regtype==3)goto rj1860;
rj1856: emw=0;
rj1858: goto rj1884;
rj1860: segerror=emd+1;
rj1862: goto rj1856;
// 1864 REM case absolute offset [8888] mdpat&=1
// 1866 REM case reg+absolute offset
// [R?+8888] mdpat&=231 base four
// 1868 REM one reg+reg+ absolute
// offset [R?+R?+8888] mdpat&=23231
// 1870 REM CASE [nonregister]
//  mdpat&=2
// 1872 REM case 1872 [reg+nonregister]
// mdpat&=232 to 231
// 1874 REM one  [reg+reg+nonregister]
// mdpat&=23232
// 1876 REM case [register]
//     mdpat&=2
// 1878 REM case 1878 [register+register]
// mdpat& stays 232
// already char rcmpval[80];
rj1884: eebelcopy(rcmpval,"4G1.........",12);
// OK ***ERROR *** rj1884:rcmpval$="4G1"
rj1886: rh1650();
rj1888: if(tcmpval != mdpat)goto rj1896;
  if(btwofour==4)goto rj5136;
// ?? ***ERROR*** 1536 is outside normal range *
rj1890: offsetloc=0+1024;
rj1892: mduuuram=6;
rj1893: emsize=3;
rj1894: goto rj1782;
rj1896: eebelcopy(rcmpval,"4G231.......",12);
// OK *** ERROR *** zj1896: rcmpval$="4G231"
  rh1650();
rj1900: if(tcmpval != mdpat)goto rj1934;
  if(btwofour == 4)goto rj5095;
// 1903 REM mdpat&=231
rj1904: regbase=1024;
  ri1690();
  if(regindex != 6)goto rj1916;
rj1910: mduuuram=128+4;
rj1912: offsetloc=1024+((arcsymlen+2)*2);
  goto rj1893;
rj1916: if(regindex != 7)goto rj1922;
  mduuuram=128+5;
  goto rj1912;
rj1922: if(regindex != 5)goto rj1928;
  mduuuram=128+6;
  goto rj1912;
rj1928: if(regindex != 3)goto rj1782;
  mduuuram=128+7;
rj1932: goto rj1912;
rj1934: eebelcopy(rcmpval,"4G23231.....",12);
// OK ****ERROR*** rj1934: rcmpval="4G23231"
  rh1650();
  if((tcmpval+1)==mdpat)goto rj1942;
  if(tcmpval != mdpat)goto rj1985;
  regbase=1024;
  if(btwofour == 4)goto rj5126;
rj1942: regbase=1024;
  if(btwofour == 4)goto rj1782;
  ri1690();
  pegindex=regindex;
  regbase=1024+((arcsymlen+2)*2);
  ri1690();
  if(pegindex==3)goto rj1958;
  if(pegindex==5)goto rj1974;
  goto rj1782;
rj1958: if(regindex != 6)goto rj1966;
  mduuuram=128+0;
rj1962: offsetloc=1024+(4*(arcsymlen+2));
  goto rj1893;
rj1966: if(regindex != 7)goto rj1782;
  mduuuram=128+1;
  goto rj1962;
rj1974: if(regindex != 6)goto rj1980;
  mduuuram=128+2;
  goto rj1962;
rj1980: if(regindex != 7)goto rj1782;
  mduuuram=128+3;
rj1982: goto rj1962;
rj1985: eebelcopy(rcmpval,"4G232.......",12);
// OK  ***ERROR*** rj1985: rcmpval$="4G232"
  rh1650();
  if(tcmpval != mdpat)goto rj2034;
  regbase=1024;
  if(btwofour == 4)goto rj5095;
  ri1690();
  pegindex=regindex;
  regbase=1024+(2*(arcsymlen+2));
  ri1690();
  if(regtype==1777)goto rj1904;
  if(pegindex==3)goto rj2004;
  if(pegindex==5)goto rj2020;
  goto rj1782;
rj2004: if(regindex != 6)goto rj2014;
  mduuuram=0;
// zj2008: REM no offsetloc% in [reg+reg]
rj2010: emsize=1;
  goto rj1782;
rj2014: if(regindex != 7)goto rj1904;
  mduuuram=1;
  goto rj2010;
rj2020: if(regindex != 6) goto rj2028;
  mduuuram=2;
  goto rj2010;
rj2028: if(regindex != 7) goto rj1904;
rj2030: mduuuram=3;
  goto rj2010;
rj2034: eebelcopy(rcmpval,"4G2.........",12);
// OK *** ERROR *** zj2034 rcmpval$="4G2"
  rh1650();
  if(tcmpval != mdpat)goto rj5023;
  if(btwofour==4)goto rj5109;
  regbase=1024+0;
  ri1690();
  if(regindex != 6)goto rj2054;
  mduuuram=4;
// zj2048: REM offsetloc% is not used in [reg]
rj2050: goto rj2010;
rj2054: if(regindex != 7)goto rj2060;
  mduuuram=5;
  goto rj2050;
rj2060: if(regindex != 3)goto rj1890;
  mduuuram=7;
  goto rj2050;
// zj2065: REM 2066 old return without [ ],imed
rj2066: ddimed=0;
  iml=0;
  imh=0;
  onereg=1024;
  if(lasttype != 1)goto rj2096;
  if(xrbase==0)goto rj2090;
  harbase=xrbase-(arcsymlen+2);
  harbw=linesymms[sc((harbase+2),1024,22066)];
  emw=1;
  if(harbw==66)goto rj2088;
  if(harbw==98)goto rj2088;
  goto rj2090;
rj2088: emw=0;
rj2090: dlbase=lastpos;
  rg1560();
rj2096: if(mduuuram < 256)goto rj2116;
  if(lasttype != 2)goto rj2116;
  regbase=lastpos;
  ri1690();
  if(regtype==1777)goto rj2116;
  segerror=0;
  emw=0;
  if(regtype<3)goto rj2112;
  segerror=8;
  goto rj2114;
rj2112: emw=2-regtype;
rj2114: onereg=regindex;
rj2116: if(lasttype==1)goto rj2129;
  if(xrbase==0)goto rj2129;
  if(xxregxxx<256)goto rj2129;
  if(mduuuram>255)goto rj2129;
  if(harbase < (2*(arcsymlen+2)))goto rj2129;
  emw=1;
  harbase=xrbase-(arcsymlen+2);
  harbw=linesymms[sc((harbase+2),1024,22116)];
  if(harbw==66)goto rj2130;
  if(harbw==98)goto rj2130;
rj2129: goto rj2131;
rj2130: emw=0;
rj2131: if(xrbase < (3*(arcsymlen+2)))goto rj2141;
  harbase=xrbase-(arcsymlen+2);
  hlrbw=linesymms[sc((harbase+1),1024,22131)];
  harbw=linesymms[sc((harbase+2),1024,22131)];
  if(hlrbw != 4)goto trj2138;
  if(btwofour != 2)goto trj2138;
  if(harbw==119)goto rj2140;
// zj2137: REM Word length override
// for shr word [bp+iuy],cl
  if(harbw==87)goto rj2140;
  goto rj2141;
trj2138: if(hlrbw != 5)goto rj2141;
  if(btwofour != 4)goto rj2141;
  if(harbw == 100)goto rj2140;
  if(harbw ==  68)goto rj2140;
  goto rj2141;
rj2140: emw=1;
rj2141: goto rj2144;
// -
rj5023:  eebelcopy(rcmpval,"4G2323131...",12);
// OK *** ERROR*** rj5023 rcmpval$="4G2323131"
// 5024 REM 5023 32-bit [ebp+edi*1+0h]
rj5025: rh1650();
    if((tcmpval+1) == mdpat)goto rj5028;
rj5027: if(tcmpval != mdpat)goto rj1782;
rj5028: if(btwofour != 4)goto rj1782;
  goto rj5060;
// -------------------------------
// zj5057 REM 5060 fix 32-bit 2323131
rj5060: emsize = 6;
rj5061: mduuuram = 128+4;
rj5062: offsetloc=1024+(6*(arcsymlen+2));
rj5063: regbase = 1024;
  ri1690();
  pegindex = regindex;
  regbase = 1024 + (2*(arcsymlen+2));
  ri1690();
  ssdexbas = ( regindex * 8 ) + pegindex;
  regbase = 1024 + (4*(arcsymlen+2));
  tj5040();
  if(nonreg < 256)goto rj5086;
// 5079 REM prefix instruction mdregram
// ssdexbas a0 a1 a2 a3  D0 D1 D2 D3
rj5080: mduuuram = 1777;
  xxregxxx = 1777;
  goto rj1782;
rj5086: ssdexbas = ssdexbas + nonreg;
rj5089: goto rj1782;
// 5094 REM 5095 fix 32-bit 231  [ecx+0000h]
rj5095: emsize = 5;
  offsetloc = 1024+(2*(arcsymlen+2));
  regbase = 1024;
  ri1690();
  mduuuram = 128 + regindex;
  goto rj1782;
// 5107 REM 5109 fix  2  [ecx]    32-bit
rj5109: emsize = 1;
  regbase = 1024;
  ri1690();
  mduuuram = regindex;
  if(regindex==4)goto rj5080;
  if(regindex==5)goto rj5080;
  goto rj1782;
// 5124 REM 5126 partial fix of
// 32-bit 23231  [edx+esi*4]
rj5126: emsize = 2;
  mduuuram=4;
  goto rj5063;
// 5134 REM 5136 fix 1 in
// 32-bit mode [8888]
rj5136: offsetloc = 1024;
rj5138: mduuuram = 5;
  emsize = 5;
  goto rj1782;
// ----------------
rj2144: botdummy=0;
  }
// ----------------
// zj5038 REM tj5040 get nonreg% from regbase%
  void tj5040()
  {
trj5040: nonreg = 512;
  if(regbase > 1023)goto tj5048;
  cregchr=linesymms[sc((2+regbase),1024,25040)];
  goto tj5050;
tj5048: ile429=sc((2+regbase-1024),256,25048);
  cregchr = mdregrtm[ile429];
tj5050: if(cregchr=='1')nonreg = 0;
  if(cregchr=='2')nonreg = 64;
  if(cregchr=='4')nonreg = 128;
  if(cregchr=='8')nonreg = 192;
  botdummy=0;
  }
// --
// 5147 REM subroutine 5148 iml% save
//  using z514% = 0
  void tj5148()
  {
ttj5148: z514 = 0;
ttjv148: tj5149();
  }
  void tj5149()
 {
tj5149: ile429=sc((3+qteepvar + z514),80,5149);
  isthold[ile429]=iml;
  isthold[sc((4+qteepvar + z514),80,5149)]=imh;
  if(btwofour != 4)goto tj5164;
  isthold[sc((5+qteepvar + z514),80,5149)]=imhh;
  isthold[sc((6+qteepvar+z514),80,5149)]=imhhh;
  if(qteepvar==0)goto tj5164;
  if(z514 != 0)goto tj5164;
  isthold[3]=ssdexbas;
tj5164: botdummy=0;
  }
// -
// 5165 REM 5166 iml% save using
// z514% = emsize% - qteepvar%
 void tj5166()
     {
ttj5166: z514 = emsize - (qteepvar + 1);
ttj5168: tj5149();
     }
// 5169 REM 5170 JMP or CALL difference save
   void tj5170()
      {
ttj5170: z514 = 0 - (qteepvar + 1);
ttj5172: tj5149();
      }
// -----
// -----
// 2146 REM rku2150 get lslen% FROM stpos%
 void rku2150()
 {
sdk2150: lslen=0;
zku2152: if(stpos>stlen)goto rku2168;
zku2154: lsptr=((stpos-1)*(arcsymlen+4))+4;
// is starting position still 2 ?? no.
rku2156: chctarg=bigsym[sc(lsptr,bigsymlim,22156)];
zku2158: lsptr=lsptr+1;
// zku2160: lschka=(long)chctarg;
zku2160: lschka=iamfromc(chctarg);
zku2162: if(lschka<33)goto rku2168;
zku2164: lslen=lslen+1;
zku2166: if(lslen < arcsymlen)goto rku2156;
// is term size ==14 ?? no
rku2168: botdummy=0;
 }
// 2169 REM 2170 or 2171 iml%,imh%,ddimed&
// xor notfound% FROM sybase% OR lc&
  void rk2170()
  {
rrk2170: overwrt=0;
rzk2170: rl2171();
  }
  void rl2171()
  {
rrl2171: notfound=1;
rl2172: if(sybase>1023)goto rl2178;
// REM overwrt%=0 for normal symbol, nonzero
// to overwrite exsisting symbol
  lschrb=linesymms[sc((sybase+1),1024,22172)];
  goto rl2180;
rl2178: ile429=sc(((sybase-1024)+1),256,22178);
  lschrb=mdregrtm[ile429];
rl2180: sylenb=(long)lschrb;
  stpos=1;
rl2184: rku2150();
  if(lslen==0)goto rl2239;
  if(lslen==sylenb)goto rl2196;
// zl2190: REM 2192 unequal
rl2192: stpos=stpos+1;
  goto rl2184;
rl2196: sycpos=2;
  syepos=((stpos-1)*(arcsymlen+4))+4;
rl2200: if(sybase>1023)goto rl2206;
  lschrc=linesymms[sc((sycpos+sybase),1024,22200)];
  goto rl2208;
rl2206: ile429=sc((sycpos+sybase-1024),256,22206);
 lschrc=mdregrtm[ile429];
rl2208: sychrc=lschrc;
  sycpos=sycpos+1;
  chctarg=bigsym[sc(syepos,bigsymlim,22208)];
  sychre=iamfromc(chctarg);
  syepos=syepos+1;
  sichre=sychre;
  if(sichre != sychrc)goto rl2192;
  if(sycpos <(lslen+2))goto rl2200;
  syepos=((stpos-1)*(arcsymlen+4));
  imlc=bigsym[sc(syepos,bigsymlim,22208)];
  imhc=bigsym[sc((syepos+1),bigsymlim,22208)];
  imhhc=bigsym[sc((syepos+2),bigsymlim,22208)];
  imhhhc=bigsym[sc((syepos+3),bigsymlim,22208)];
  iml=iamfromc(imlc);
  imh=iamfromc(imhc);
  imhh=iamfromc(imhhc);
  imhhh=iamfromc(imhhhc);
  ddimed=iml+(256*imh)+(65536*imhh);
  ddimed=ddimed+(256*65536*imhhh);
  notfound=0;
// zl2238 REM FOUND ddimed& iml% imh% notfound%=0
rl2239: if(overwrt != 0)goto rl2242;
  if(notfound==0)goto rl2272;
  stlen=stlen+1;
rl2242: ddimed=lc;
  tg1630();
  syepos=((stpos-1)*(arcsymlen+4));
  bigsym[sc(syepos,bigsymlim,2242)]=canminus(iml);
  ile429=sc((syepos+1),bigsymlim,2242);
  bigsym[ile429]=canminus(imh);
  ile429=sc((syepos+2),bigsymlim,2242);
  bigsym[ile429]=canminus(imhh);
  ile429=sc((syepos+3),bigsymlim,2242);
  bigsym[ile429]=canminus(imhhh);
  syepos=syepos+4;
  syfpos=2;
rl2256: if(sybase>1023)goto rl2262;
rl2258: ile429=sc((sybase+syfpos),1024,22258);
  symg=linesymms[ile429];
  goto rl2264;
rl2262: ile429=sybase+syfpos-1024;
  symg=mdregrtm[sc(ile429,256,22262)];
rl2264: syfpos=syfpos+1;
  bigsym[sc(syepos,bigsymlim,2264)]=canminus(symg);
  syepos=syepos+1;
  if(syfpos < (arcsymlen+2))goto rl2256;
rl2272: botdummy=0;
  }
// 2273 REM 2274 get instruction length with
// unknown symbols   cpuinlen%
    void rm2274()
    {
rrm2274: symknown=0;
// 2275 REM lc&.next. - lc& =
// resblen% + cpuinlen% returns isthold(cpuinlen%)
// 2276 REM 2278 GET instruction
// qteepvar% == 0 if no sib byte
// 2277 REM  wrdis%=0 to write
xrm2277: rn2278();
   }
   void rn2278()
   {
rrn2278: istlbase=arcsymlen+2;
rn2279: cpuinlen=1;
rn2280: ile429=sc(istlbase,1024,22280);
  isttype=(long)linesymms[ile429];
  resblen=0;
  ile429=sc((istlbase+1),1024,22280);
  istlen=(long)linesymms[ile429];
  if(isttype==0)goto rn2494;
  if(istlen<2)goto rn2288;
  if(isttype==2)goto rn2296;
rn2288: errorlin=2288;
rn2290: crash=1;
// 2292 REM rn2290 error  2293 cpuinlen%=0
// exit 2294 goto quit
rn2293: cpuinlen=0;
rn2294: goto rn3998;
rn2296: goto rn2439;
// ---
rn2439: qteepvar = 0;
rn2440: rj1760();
rn2441: if(ssdexbas != 0)qteepvar = 1;
rn2442: searlim=hlong101(u)-3;
  ibasesub=1;
  rchosen=0;
// 2446 REM first checklength = istlen%
// blankloop=2448
rn2448: instchr=u[sc((ibasesub-1),4096,22448)];
  if(instchr != 32)goto rn2456;
  ibasesub=ibasesub+1;
  if(ibasesub<searlim)goto rn2448;
  goto rn2494;
rn2456: tabilen=0;
rn2458: ile429=0;
  ile429=sc((ibasesub+tabilen-1),4096,22458);
  instchr=u[ile429];
  if(instchr==32)goto rn2465;
  tabilen=tabilen+1;
  if(tabilen < arcsymlen)goto rn2458;
rn2465: rchosen=rchosen+1;
  if(tabilen==istlen)goto rn2472;
// zn2467 REM 2468 unequal
rn2468: ibasesub=ibasesub+tabilen;
  goto rn2448;
rn2472: tabictr=0;
rn2474: ile429=0;
  instchr=u[sc((ibasesub+tabictr-1),4096,22474)];
rn2476: ile429=istlbase+2+tabictr;
  rinstchr=linesymms[sc(ile429,1024,22476)];
  if(instchr==rinstchr)goto rn2488;
  if(instchr<65)goto rn2486;
  if(instchr>90)goto rn2486;
  ile429=0;
  if((long)(instchr+32)==(long)(rinstchr))
  {
  ile429=1;
  }
  if(ile429 == 1)goto rn2488;
rn2486: goto rn2468;
rn2488: tabictr=tabictr+1;
rn2490: if(tabictr<tabilen)goto rn2474;
// zn2492 REM 2494 equal
rn2494: if(symknown != 0)goto rn2511;
  labelen=(long)linesymms[1];
  if(labelen<1)goto rn2511;
  sybase=0;
  rk2170();
  if(notfound != 0)goto rn2511;
  errorlin=2505;
  goto rn2290;
rn2507: errorlin=2507;
  goto rn2290;
rn2509: errorlin=2509;
  goto rn2290;
rn2511: denom=8;
  dnumer=rchosen-1;
  rf1540();
  irem8=drer;
  dnumer=dfrac;
  rf1540();
  igti=drer+1;
  dnumer=dfrac;
  rf1540();
  igto=drer+1;
  denom=16;
  dnumer=rchosen-1;
  rf1540();
  irem16=drer;
  if(isttype==0)goto rn2293;
  ihctr=0;
rn2540: ihctr=ihctr+1;
  isthold[sc((ihctr-1),80,2540)]=0;
rn2544: if(ihctr<80)goto rn2540;
rn2568: if(igto==1)goto rn2570;
  if(igto==2)goto rn2573;
  if(igto==3)goto rn2574;
  if(igto==4)goto rn2576;
  if(igto==5)goto rn2578;
  if(igto==6)goto rn2507;
  if(igto==7)goto rn2507;
  if(igto==8)goto rn2507;
  goto rn2507;
// rn2568 ON igto% GOTO 2570,2573,2574,
//  2576,2578,2507,2507,2507
rn2570: if(igti==1)goto rbr2570a;
  if(igti==2)goto rn2571;
  if(igti==3)goto rn2588;
  if(igti==4)goto rn2708;
  if(igti==5)goto rn2744;
  if(igti==6)goto rn2782;
  if(igti==7)goto rn2802;
  if(igti==8)goto rn2507;
// rn2570 ON igti% GOTO 2507,2571,
//  2588,2708,2744,2782,2802,2507
rbr2570a:  igtix=irem8+1;
  if((igtix <= 4)&&(igtix >= 1))goto rn2507;
  if(igtix == 5)goto rn3274;
  if(igtix == 6)goto rn3328;
  if(igtix == 7)goto rn3273;
  if(igtix == 8)goto rn3326;
rn2571: igtix=irem8+1;
rn2572: if(igtix==1)goto rn3166;
  if(igtix==2)goto rn3218;
  if(igtix==3)goto rn3276;
  if(igtix==4)goto rn3290;
  if(igtix==5)goto rn3332;
  if(igtix==6)goto rn3340;
  if(igtix==7)goto rn3350;
  if(igtix==8)goto rn3366;
// rn2572 ON igtix% GOTO 3166,3218,3276,
//  3290,3332,3340,3350,3366
rn2573: if(igti==1)goto rn2816;
  if(igti==2)goto rn2816;
  if(igti==3)goto rn2816;
  if(igti==4)goto rn2816;
  if(igti==5)goto rn2846;
  if(igti==6)goto rn2854;
  if(igti==7)goto rn2874;
  if(igti==8)goto rn2874;
// rn2573 ON igti% GOTO 2816,2816,2816,
// 2816,2846,2854,2874,2874
rn2574: if(igti==1)goto rn2888;
  if(igti==2)goto rn2900;
  if(igti==3)goto rn2906;
  if(igti==4)goto rn2986;
  if(igti==5)goto rn3028;
  if(igti==6)goto rn3042;
  if(igti==7)goto rn3066;
  if(igti==8)goto rn3074;
// rn2574 ON igti% GOTO 2888,2900,2906,
//  2986,3028,3042,3066,3074
rn2576: if(igti==1)goto rn3080;
  if(igti==2)goto rn3080;
  if(igti==3)goto rn3086;
  if(igti==4)goto rn3096;
  if(igti==5)goto rn3102;
  if(igti==6)goto rn3108;
  if(igti==7)goto rn3114;
  if(igti==8)goto rn3114;
// rn2576 ON igti% GOTO 3080,3080,
//  3086,3096,3102,3108,3114,3114
rn2578: if(igti==1)goto rn3120;
  if(igti==2)goto rn3126;
  if(igti==3)goto rn3134;
  if(igti==4)goto rn3140;
  if(igti==5)goto rn3148;
  if(igti==6)goto rn3154;
  if(igti==7)goto rn3160;
  if(igti==8)goto rn2580;
// rn2578 ON igti% GOTO 3120,3126,
//  3134,3140,3148,3154,3160,2580
rn2580: igtix=irem8+1;
rn2582: if(igtix==1)goto rn3372;
  if(igtix==2)goto rn3388;
  if(igtix==3)goto rn3424;
  if(igtix==4)goto rn3428;
  if(igtix==5)goto rn3476;
  if(igtix==6)goto rn2507;
  if(igtix==7)goto rn2507;
  if(igtix==8)goto rn2507;
// rn2582 ON igtix% GOTO 3372,3388,3424,
//  3428,3476,2507,2507,2507
// 2586 REM 2588 ADD OR ADC SBB AND
// SUB XOR CMP  series
rn2588: if(segerror==0)goto rn2594;
// 2589 REM 2590 unwanted segment
// register error
rn2590: errorlin=2590;
rn2592: goto rn2290;
rn2594: if(lasttype==1)goto rn2658;
rn2595: isthold[1]=0+(8*irem8)+(2*emd)+emw;
  if(isthold[1]>255)goto rn2601;
// 97 REM 2598 GENERAL reg,mdregr/m  reg
// is 8*ist for unary [mem] not immediate
rn2598: isthold[2]=mduuuram+xxregxxx;
  if(isthold[2]<256)goto rn2604;
rn2601: errorlin=2601;
  goto rn2290;
// zn2603 REM 2601 invalid mdregr/m
rn2604: cpuinlen=1+emsize;
rn2606: ile429 = 1 + btwofour + qteepvar;
   if(emsize == ile429)goto rn2610;
  goto rn2294;
rn2610: if(symknown != 0)goto rn2614;
  goto rn2294;
rn2614: ile429=0;
  ile429=sc((offsetloc-1024),256,22614);
  atype=(long)mdregrtm[ile429];
  if(atype==1)goto rn2624;
  if(atype==2)goto rn2642;
rn2620: errorlin=2620;
// 2621 REM 2620 late caught invalid mdregr/m
  goto rn2290;
rn2624: dlbase=offsetloc;
   rg1560();
rn2628:  tj5148();
rn2640: goto rn2294;
rn2642: sybase=offsetloc;
  rk2170();
  if(notfound==0)goto rn2652;
// zn2647:  REM 2648 error undefined symbol
rn2648: errorlin=2648;
rn2650: goto rn2290;
rn2652: goto rn2628;
rn2658: isthold[1]=128+emw;
  if(isthold[1]>255)goto rn2601;
rn2660: isthold[2]=mduuuram+(8*irem8);
// zn2661: REM 2660 general mdregr/m,imed
  if(isthold[2]>255)goto rn2601;
  cpuinlen = 2+emsize+(emw * (btwofour - 1));
rn2665: if(segerror != 0)goto rn2590;
rn2666: if(emsize == (1 + qteepvar))goto rn2698;
rn2668: if(symknown==0)goto rn2698;
  ile429=sc((offsetloc-1024),256,22668);
  atype=(long)mdregrtm[ile429];
  if(atype==1)goto rn2678;
  if(atype==2)goto rn2688;
  goto rn2620;
rn2678: dlbase=offsetloc;
  rg1560();
rn2682: tj5148();
  goto rn2698;
rn2688: sybase=offsetloc;
  rk2170();
  if(notfound != 0)goto rn2648;
rn2694: tj5148();
rn2698: dlbase=lastpos;
  rg1560();
rn2700: tj5166();
  goto rn2294;
// rn2706 REM 2708 MOV
rn2708: if(lasttype==1)goto rn2736;
  if(segerror != 0)goto rn2718;
  isthold[1]=136+(2*emd)+emw;
rn2714: if(isthold[1]>255)goto rn2601;
  goto rn2598;
rn2718: if(xrbase==0)goto rn2724;
  isthold[1]=140+(2*emd);
  goto rn2714;
rn2724: isthold[1]=140;
  if(segerror==1)goto rn2730;
  goto rn2714;
rn2730: isthold[1]=142;
  if(xxregxxx==8)goto rn2601;
  goto rn2714;
rn2736: isthold[1]=198+emw;
  if(isthold[1]>255)goto rn2601;
  goto rn2660;
// 2742 REM 2744 PUSH
rn2744: if(xrbase==0)goto rn2752;
  xxregxxx=48;
  isthold[1]=255;
  goto rn2598;
rn2752: if(segerror != 0)goto rn2770;
  lefnib=80;
// zn2756 REM 2758 single
// general register operand
rn2758: isthold[1]=lefnib+onereg;
  if(isthold[1]>255)goto rn2601;
  if(segerror != 0)goto rn2590;
rn2762: cpuinlen=1;
  goto rn2294;
rn2770: lefnib=6;
// 2772 REM 2774 single segment register
//  operand to push or pop
rn2774: isthold[1]=lefnib+(8*onereg);
  if(isthold[1]>255)goto rn2601;
  goto rn2762;
// 2780 REM 2782 POP
rn2782: if(xrbase==0)goto rn2790;
  xxregxxx=0;
  isthold[1]=143;
  goto rn2598;
rn2790: if(segerror != 0)goto rn2796;
  lefnib=88;
  goto rn2758;
rn2796: lefnib=7;
rn2797: if(onereg==1)goto rn2601;
rn2798: goto rn2774;
// 2800 REM 2802 INC DEC
rn2802: if(xrbase==0)goto rn2810;
  xxregxxx=8*irem8;
  isthold[1]=254+emw;
  goto rn2598;
rn2810: lefnib=64+(8*irem8);
rn2812: goto rn2758;
// rn2814 REM 2816 J (cond)
rn2816: isthold[1]=112+irem16;
// 2817 REM 2818 shared J (cond) JCXZ
rn2818: cpuinlen=2;
  if(lasttype==1)goto rn2838;
  if(symknown==0)goto rn2836;
  sybase=lastpos;
  rk2170();
  if(notfound != 0)goto rn2648;
  prntemp=ddimed;
  ddimed=(ddimed-lc)-2;
  if(ddimed<(0-128))goto rn2842;
  if(ddimed>127)goto rn2842;
  tg1630();
rn2834: isthold[2]=iml;
rn2836: goto rn2294;
rn2838: dlbase=lastpos;
rn2839: rg1560();
  goto rn2834;
rn2842: errorlin=2842;
// short conditional jump range exceeded 2842
  goto rn2290;
// 2845 REM 2846 seg override
rn2846: isthold[1]=38+(8*irem8);
rn2848: cpuinlen=1;
  goto rn2294;
// 2852 REM 2854 ret retf c2+(not imed)+8*irem8%
rn2854: isthold[1]=194+8*(irem8);
  if(lasttype==1)goto rn2860;
  isthold[1]=isthold[1]+1;
  goto rn2848;
rn2860: dlbase=lastpos;
  rg1560();
  tj5170();
rn2868: cpuinlen = btwofour + 1;
  goto rn2294;
// zn2872 REM 2874 shifts lasttype%=1 for v=0
rn2874: vv=0;
  if(lasttype==1)goto rn2884;
rn2876: ile429=1 + btwofour + qteepvar;
  if(emsize == ile429)goto rn2883;
  denom=8;
// zn2878: REM IF 2882 fix emw%=word
//  for all shift reg,cl
  dnumer=xxregxxx;
  rf1540();
  mduuuram=192+dfrac;
// zn2882 REM emw%=1
rn2883: vv=2;
rn2884: isthold[1]=208+vv+emw;
  xxregxxx=8*irem8;
  goto rn2598;
// 2887 REM 2888 LEA
rn2888: isthold[1]=141;
rn2890: if(segerror != 0)goto rn2588;
rn2891: ile429=1 + btwofour + qteepvar;
  if(emsize != ile429)goto rn2620;
  if(emw<1)goto rn2601;
  if(lasttype != 3)goto rn2620;
  if(xrbase==0)goto rn2620;
  goto rn2598;
// 2898 REM 2900 9c+irem8%*1
// single byte  pushf popf sahf lahf
rn2900: isthold[1]=156+irem8;
  goto rn2848;
// 2904 REM 2906 call
rn2906: if(linepat==165)goto rn2916;
        if(linepat==166)goto rn2916;
  if(mduuuram<255)goto rn2940;
  if(onereg<255)goto rn2938;
  if(linepat==10)goto rn2962;
  if(linepat==42)goto rn2962;
  goto rn2601;
rn2916: isthold[1]=154;
// 2917 REM 2918 common call jump far constants
rn2918: dlbase=lastpos;
  if(linepat != 165)goto rn2920;
  rg1560();
  goto rn2922;
rn2920: sybase=dlbase;
  rk2170();
  if(notfound != 0)goto rn2648;
rn2922: isthold[2]=iml;
rn2924: isthold[3]=imh;
  if(btwofour < 3)goto rn2926;
  isthold[4]=imhh;
  isthold[5]=imhhh;
rn2926:  dlbase=lastpos-(arcsymlen+2);
  rg1560();
rn2930: isthold[(btwofour+2)]=iml;
rn2932: isthold[(btwofour+3)]=imh;
rn2934: cpuinlen=3+btwofour;
  goto rn2294;
rn2938: mduuuram=192+onereg;
rn2940: calpos=xrbase-(arcsymlen+2);
  cachk=linesymms[sc((calpos+2),1024,22940)];
  if(cachk==70)goto rn2956;
  if(cachk==102)goto rn2956;
  xxregxxx=16;
  goto rn2958;
rn2956: xxregxxx=24;
rn2958: isthold[1]=255;
  goto rn2598;
rn2962: isthold[1]=232;
// 2963 REM 2964 common call jump realative 16
rn2964: cpuinlen = btwofour + 1;
  if(symknown==0)goto rn2982;
  sybase=lastpos;
  rk2170();
  if(notfound != 0)goto rn2648;
  ddimed=(ddimed-lc)-(btwofour+1);
  tg1630();
rn2978: tj5170();
rn2982: goto rn2294;
// 2984 REM 2986 JMP
rn2986: if(linepat==165)goto rn2998;
  if(linepat==166)goto rn2998;
  if(mduuuram<255)goto rn3004;
  if(onereg<255)goto rn3002;
  if(linepat==10)goto rn3022;
  if(linepat==42)goto rn3022;
rn2996: goto rn2601;
rn2998: isthold[1]=234;
  goto rn2918;
rn3002: mduuuram=192+onereg;
rn3004: calpos=xrbase-(arcsymlen+2);
  cachk=linesymms[sc((calpos+2),1024,23004)];
  if(cachk==70)goto rn3016;
  if(cachk==102)goto rn3016;
  xxregxxx=32;
  goto rn3018;
rn3016: xxregxxx=40;
rn3018: isthold[1]=255;
  goto rn2598;
rn3022: isthold[1]=233;
  goto rn2964;
// 3026 REM 3028 TEST
rn3028: if(lasttype==1)goto rn3034;
  isthold[1]=132+emw;
  goto rn2598;
rn3034: isthold[1]=246+emw;
  goto rn2660;
// 3040 REM 3042 in
rn3042: cpuinlen=1;
// 3043 REM emw%=0
rn3044: isthold[1]=228+irem8+emw;
  if(isthold[1]>255)goto rn2601;
  if(lasttype != 1)goto rn3060;
// zn3047 REM IF 3043 Width=byte for
// ALL I/O. use DB hex for exception.
// zn3048 REM 3050 I/O with immediate byte
// common with interrupt type
rn3050: dlbase=lastpos;
  rg1560();
rn3054: cpuinlen=2;
  isthold[2]=iml;
  goto rn2294;
rn3060: isthold[1]=isthold[1]+8;
  goto rn2294;
// zn3064 REM 3066 into iret series
rn3066: isthold[1]=206+irem8;
rn3068: cpuinlen=1;
  goto rn2294;
// zn3072 REM 3074 int byte
rn3074: isthold[1]=205;
  goto rn3050;
// 3078 REM 3080 single byte character
// series a4+irem16%
rn3080: isthold[1]=164+irem16;
  goto rn3068;
// zn3084 REM 3086 not neg
rn3086: isthold[1]=246+emw;
  xxregxxx=8*irem8;
  if(xrbase != 0)goto rn3092;
  mduuuram=192+onereg;
rn3092: goto rn2598;
// 3094 REM 3096 NOP series 90+irem8*1
rn3096: isthold[1]=144+irem8;
  goto rn3068;
// zn3100 3102 loopne series e0+irem8*1  JCXZ
rn3102: isthold[1]=224+irem8;
  goto rn2818;
// 3106 REM 3108 LES c4+irem8*1 mdregr/m
rn3108: isthold[1]=196+irem8;
  goto rn2598;
// 3112 REM 3114 lock series two repz
// rep f0+irem8%*1 single byte
rn3114: isthold[1]=240+irem8;
  goto rn3068;
// 3118 3120 clc series F8+irem8%*1 single byte
rn3120: isthold[1]=248+irem8;
  goto rn3068;
// 3124 REM 3126 MUL series
rn3126: xxregxxx=8*irem8;
  isthold[1]=246+emw;
  goto rn2598;
// 3132 REM 3134 XCHG 86+emw
rn3134: isthold[1]=134+emw;
  goto rn2598;
// zn3138 REM 3140 2422 unknown group 27+irem8*8
rn3140: isthold[1]=39+irem8*8;
rn3142: cpuinlen=1;
  goto rn2294;
// zn3146 unknown immediate 8 group irem8*1
rn3148: isthold[1]=216+irem8;
  goto rn3050;
// rn3152 REM 3154 XLATB D7
rn3154: isthold[1]=215;
  goto rn3142;
// 3158 3160 CBW single byte series 98+irem8*1
rn3160: isthold[1]=152+irem8;
  goto rn3142;
// 3164 REM DB 3166
rn3166: dacd=2*(arcsymlen+2);
rn3167: cpuinlen=0;
rn3169: cdtype=linesymms[sc(dacd,1024,23169)];
  cdlen=(long)linesymms[sc((dacd+1),1024,23169)];
  if(cdtype==0)goto rn3214;
  if(cdtype==1)goto rn3184;
  if(cdtype==2)goto rn3196;
// 3178 REM 3180 error in DB statement
rn3180: errorlin=3180;
  goto rn2290;
rn3184: dlbase=dacd;
  rg1560();
  cpuinlen=cpuinlen+1;
  isthold[sc(cpuinlen,80,3184)]=iml;
  dacd=dacd+arcsymlen+2;
  goto rn3169;
rn3196: bucd=0;
rn3198: bucd=bucd+1;
  if(bucd>cdlen)goto rn3210;
  cdg=linesymms[sc((dacd+1+bucd),1024,23198)];
  cpuinlen=cpuinlen+1;
  isthold[sc(cpuinlen,80,3198)]=cdg;
  goto rn3198;
rn3210: dacd=dacd+arcsymlen+2;
  if(cdlen < (arcsymlen+1))goto rn3169;
rn3214: goto rn2294;
// 3216 REM 3218 DW
rn3218: wdarcsel=2;
rn3219: cpuinlen=0;
  denom=wdarcsel;
rn3224:  dnumer=lc;
rn3225:  rf1540();
       phasecor=wdarcsel-drer;
       if(drer==0)goto rn3249;
      if(alignzur == 0)goto rn3230;
      if(alignwarn != 0)goto rn3230;
// ERROR UNALIGNED 3228
rn3228:  errorlin=3228;
      goto rn2290;
rn3230:  if(alignzur != 0)goto rn3249;
//   alignzur == 0 for alignment
  if(drer==0)goto rn3249;
  dacd=0;
  cdtype=linesymms[sc(dacd,1024,23218)];
  if(cdtype==0)goto rn3246;
  lc=lc+cpuinlen+1;
  sybase=0;
  overwrt=1;
  rl2171();
  lc=lc-(cpuinlen+1);
rn3246: cpuinlen=cpuinlen+1;
  isthold[sc(cpuinlen,80,3246)]=144;
  dnumer=lc+cpuinlen;
  goto rn3225;
rn3249: dacd=2*(arcsymlen+2);
rn3250: cdtype=linesymms[sc(dacd,1024,23250)];
  cdlen=linesymms[sc((dacd+1),1024,23250)];
  if(cdtype==0)goto rn2294;
  if(cdtype==1)goto rn3258;
  goto rn3180;
rn3258: dlbase=dacd;
rn3260: rg1560();
  isthold[sc((cpuinlen+1),80,3260)]=iml;
  isthold[sc((cpuinlen+2),80,3260)]=imh;
  if(wdarcsel < 3)goto rn3265;
  isthold[sc((cpuinlen+3),80,3260)]=imhh;
  isthold[sc((cpuinlen+4),80,3260)]=imhhh;
rn3265:  cpuinlen=cpuinlen+wdarcsel;
  dacd=dacd+arcsymlen+2;
rn3272: if(cdlen < (arcsymlen+1))goto rn3250;
   goto rn2294;
// rn3273 DD        rn3274 DQ
rn3273: wdarcsel=4;
  goto rn3219;
rn3274: wdarcsel=8;
  goto rn3219;
// 3275 REM 3276 RESB
rn3276: dlbase=lastpos;
  wrdis=1;
  rg1560();
  resblen=ddimed*incstep;
// zn3282 REM 3284 cpuinlen%=0 EXIT
rn3284: cpuinlen=0;
  goto rn2294;
// zn3288: REM 3290 RESW
rn3290: wdarcsel=2;
rn3291: resblen=0;
  wrdis=1;
  denom=wdarcsel;
rn3294:  dnumer=lc;
rn3295:  rf1540();
  phasecor=wdarcsel-drer;
  if(drer==0)goto rn3322;
  if(incstep != 1)goto rn3180;
  if(alignwarn != 0)goto rn3300;
  if(alignzur != 0)goto rn3180;
rn3300:  dacd=0;
  cdtype=linesymms[sc(dacd,1024,23290)];
  if(cdtype==0)goto rn3320;
  lc=lc+resblen+1;
  sybase=0;
  overwrt=1;
  rl2171();
  lc=lc-(resblen+1);
rn3320: resblen=resblen+1;
  dnumer=lc+resblen;
  goto rn3295;
rn3322: dlbase=lastpos;
  rg1560();
  resblen=resblen+(ddimed*incstep*wdarcsel);
  goto rn3284;
// rn3326 resd    rn3328 resq
rn3326:  wdarcsel=4;
  goto rn3291;
rn3328:  wdarcsel=8;
  goto rn3291;
// 3330 REM 3332 ORG
rn3332: dlbase=lastpos;
  rg1560();
  slc=ddimed;
// 3338 REM 3340 stackend
rn3340: lc=slc;
  wrdis=0;
  resblen=0;
  incstep=1;
  goto rn3284;
// 3348 REM 3350 stackorg
rn3350: incstep=1;
rn3352: slc=lc;
  dlbase=lastpos;
  rg1560();
  lc=ddimed;
  wrdis=1;
  resblen=0;
  goto rn3284;
// 3364 REM 3366 negorg
rn3366: incstep=0-1;
  goto rn3352;
// 3370 REM 3372 bits
rn3372: if(lasttype != 1)goto rn3381;
  dlbase=lastpos;
  rg1560();
  btwofour=2;
  if(ddimed==16)goto rn3382;
  btwofour=4;
  if(ddimed==32)goto rn3382;
rn3381: goto rn3180;
rn3382: resblen=0;
  goto rn3284;
// 3386 REM 3388 align
rn3388: dlbase=lastpos;
rn3390: rg1560();
  if(imh != 0)goto rn3180;
  if(iml==16)goto rn3400;
  if(iml==256)goto rn3404;
  goto rn3180;
rn3400: afill=144;
  goto rn3406;
rn3404: afill=0;
rn3406: denom=iml;
  cpuinlen=0;
rn3410: dnumer=cpuinlen+lc;
rn3412: rf1540();
  if(drer==0)goto rn2294;
  cpuinlen=cpuinlen+1;
  isthold[sc(cpuinlen,80,3412)]=afill;
  goto rn3410;
// 3422 REM  3424 SYMDIFF  3428 realsegdiff
rn3424: diffbot=1;
  goto rn3430;
rn3428: diffbot=16;
rn3430: if(linepat==169)goto rn3434;
rn3432: goto rn3180;
rn3434: sybase=32;
rn3436: rk2170();
  swbig=ddimed;
  if(notfound != 0)goto rn3432;
  sybase=48;
  rk2170();
  swtiny=ddimed;
  if(notfound != 0)goto rn3432;
  dlbase=lastpos;
  rg1560();
  ddimed=(ddimed+swbig)-swtiny;
  dnumer=ddimed;
  denom=diffbot;
  rf1540();
  if(drer != 0)goto rn3432;
  tg1630();
  isthold[1]=iml;
  isthold[2]=imh;
rn3470: cpuinlen=2;
  goto rn2294;
// 3474 REM 3476 SECTION
rn3476: cpuinlen=0;
rn3488: resblen=0;
rn3498: goto rn2294;
rn3998: botdummy=0;
   }
//    3999 REM 4000 main
   int main()
   {
rrq4000: rsub=0;
      elevrd = &acline[0];
      a80w=80;
      arcsymlen=15;
      washere=0;
      prntemp=0;
//    alignzur == 0 for enabling dw alignment.
// Nonzero for unaligned dw.
      alignzur=1;
//    alignwarn == 0 for halting dw on
//   bad alignment. Nonzero for ignore.
      alignwarn=0;
      aerrorln=0;
// move down to main rq4000
rq1088: bigsymlim=28671;
rq1192: topen=0;
rq1193: tclose=0;
rq4002: bigsym[sc(rsub,bigsymlim,4002)] = '\0';
  rsub=rsub+1;
  if(rsub<(bigsymlim))goto rq4002;
  slc=0;
  sln=0;
  lc=0;
  incstep=1;
  pass=1;
  stlen=0;
  symknown=0;
  scrprint(" CASM6 C  16-bit real 8086 .",77);
  scrprint(" mode assembler for DOS.",77);
  errorlin=4021;
  scrprint(" Enter name of source.",77);
  scrprint(" asm or txt file.",77);
  scrkey(kbruthie);
  fncopy260(fnruthie,kbruthie,hlong103(kbruthie,80));
// OK ***ERROR*** zq4024 line input asmname$
  scrprint(" enter name of output.",77);
  scrprint(" plain binary file result.",77);
  scrkey(kbruthie);
  fncopy260(fnpete,kbruthie,hlong103(kbruthie,80));
// OK ***ERROR*** zq4027 line input binname$
  if(hlong103(kbruthie,80) < 1)goto rq4060;
  crash=0;
  openruth();
  eoft=0;
  goto rq4042;
rq4034: eebelcopy(intruthie,
  "sln=????? pass=????? errorlin=?????...",77);
   jumbjrprn(intruthie,5,5,sln);
   jumbjrprn(intruthie,16,5,pass);
   jumbjrprn(intruthie,31,5,errorlin);
   scrprint(intruthie,77);
  eebelcopy(intruthie,
  "igto=????? igti=????? igtix=?????...",77);
   jumbjrprn(intruthie,6,5,igto);
   jumbjrprn(intruthie,17,5,igti);
   jumbjrprn(intruthie,29,5,igtix);
   scrprint(intruthie,77);
  eebelcopy(intruthie,
  "rchosen=?????.mduuuram=?????.xxregxxx=?????...",77);
   jumbjrprn(intruthie,9,5,rchosen);
   jumbjrprn(intruthie,24,5,mduuuram);
   jumbjrprn(intruthie,39,5,xxregxxx);
   scrprint(intruthie,77);
  eebelcopy(intruthie,
  "tcmpval=????????.ddimed=?????.lc=????????.....",77);
   bprntemp=tcmpval;
   bumbjrprn(intruthie,9,8,bprntemp,4);
   bprntemp=(long)ddimed;
   if(bprntemp < 0)bprntemp=0-bprntemp;
   jumbjrprn(intruthie,25,5,bprntemp);
   bprntemp=lc;
   jumbjrprn(intruthie,34,8,bprntemp);
   scrprint(intruthie,77);
  eebelcopy(intruthie,
  "mdpat=????????.linepat=????????.phasecor=??...",77);
   bprntemp=(long)mdpat;
   bumbjrprn(intruthie,7,8,bprntemp,4);
   bprntemp=(long)linepat;
   bumbjrprn(intruthie,24,8,bprntemp,4);
// prntemp needs a value
   jumbjrprn(intruthie,42,2,phasecor);
   scrprint(intruthie,77);
  eebelcopy(intruthie,
  "washere=?????.lasttype=?????.aerrorln=?????..",77);
  jumbjrprn(intruthie,9,5,washere);
  jumbjrprn(intruthie,24,5,lasttype);
  jumbjrprn(intruthie,39,5,aerrorln);
  scrprint(intruthie,77);
  eebelcopy(intruthie,"----------------",16);
  jumbjrprn(intruthie,1,7,lc);
  jumbjrprn(intruthie,10,2,phasecor);
  scrprint(intruthie,16);
  scrprint(elevrd,77);
//  scrprint(bigsym,80);
    scrprint(linesymms,80);
//  scrprint(mdregrtm,128);
  scrprint(" *** ERROR *** PROGRAM HALTED...",77);
  goto rq4998;
rq4042:  errorlin=4042;
  topen=1;
// zq4044: REM 4046 loop pass #1
rq4046: if(eofdelay != 0)goto rq4062;
   rb1200();
  if(eoft != 0)eofdelay=1;
  re1460();
// zq4052 REM 1760 is in 2274
  rm2274();
  lc=(lc+cpuinlen)+resblen;
// 4056 REM making symbol table with first pass
// 4057 REM sln=sln+1
  if(crash==0)goto rq4046;
rq4060:  goto rq4034;
rq4062:  fclose(hvruthie);
  eofi=1;
  hv0c=0;
// OK rq4062: CLOSE #1
  topen=0;
  compos=0;
  eoft=0;
  eebelcopy(intruthie,
  "sln=????? lc=???????? stlen=????.",77);
   jumbjrprn(intruthie,5,5,sln);
   jumbjrprn(intruthie,14,8,lc);
   jumbjrprn(intruthie,29,5,stlen);
   scrprint(intruthie,77);
  sln=0;
  pass=2;
  slc=0;
  lc=0;
  scrprint("  CASM6 NEEDS TWO PASSES ..",77);
  scrprint(" REMEMBER TO VOTE AGAINST RESUMING.",77);
  scrprint(" THE PEACETIME US MILITARY DRAFT ..",77);
  scrprint(" BY VOTING FOR AN ....",77);
  scrprint(" ALL VOLUNTEER JURY SYSTEM ..",77);
  openruth();
// use fnruthie[80],hvruthie
// OK zq4100: OPEN asmname$ FOR INPUT AS #1
  topen=1;
  hvpete=fopen(fnpete,"wb");
// OK zq4102: OPEN binname$ FOR BINARY AS #2
  tclose=1;
// 4104 REM 4106 loop pass #2
rq4106: if(eofdelay != 0)goto rq4146;
  rb1200();
  if(eofi != 0)eofdelay=1;
// OK  ***ERROR*** zq4108:
// IF eoft%<>0 THEN GOTO 4146
  re1460();
// zq4111: REM 1760 is in 2274
  symknown=1;
  rn2278();
// 4115 REM sln%=sln%+1
  if(crash != 0)goto rq4060;
// 4118 REM cpuinlen%>0 XOR resblen%>0 or both 0
  if(cpuinlen==0)goto rq4142;
  if(resblen != 0)goto rq4060;
  if((wrdis != 0)&&(btwofour != 4))goto rq4060;
  comctr=0;
rq4128: comctr=comctr+1;
// comchr[0]=(char)(isthold[sc(comctr,80,24128)]);
  iirtarg=isthold[sc(comctr,80,24128)];
  comchr[0]=canminus(iirtarg);
  compos=compos+1;
  fwrite(&comchr[0],1,1,hvpete);
// OK ***ERROR* zq4134: PUT #2,compos&,comchr(0)
// 4136 REM compos& starts at 1 in
// basic binary file
  if(comctr<cpuinlen)goto rq4128;
// zq4140: REM 4142 common cpuinlen% resblen%
rq4142: lc=(lc+cpuinlen)+resblen;
rq4144: goto rq4106;
rq4146: fclose(hvpete);
// OK rq4146: CLOSE #2
rq4147: tclose=0;
rq4148: fclose(hvruthie);
// OK rq4148: CLOSE #1
rq4149: topen=0;
rq4160: eebelcopy(intruthie,"compos=??????..",77);
  jumbjrprn(intruthie,8,8,compos);
  scrprint(intruthie,77);
// OK rq4160: PRINT compos&
rq4998: rsub=0;
rq4999: if(topen==0)goto rq5010;
rq5002: fclose(hvruthie);
// REM OK rq5002: CLOSE #1
rq5010: if(tclose==0)goto rq8021;
rq5012: fclose(hvpete);
// REM rq5012: CLOSE #2
rq5014: goto rq8021;
// cut
rq8021: rsub=1;
// 8022 SYSTEM
// return 0;
 exit(0);
 }
// This is the last line of this program.
// hvruthie is read handle for source .asm file.
// casm6.c 16 and 32 bit intel style assembler in C
// 08-10-2017

