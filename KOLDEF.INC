{-----------------------------------------------------------------------------
  Version detection for Delphi and Free Pascal
  Supports Delphi 2..12 Athens and FPC 2.6+
-----------------------------------------------------------------------------}

{--- Delphi 2 .. 5 (no CONDITIONALEXPRESSIONS) ------------------------------}
{$IFDEF VER90}  // Delphi 2
  {$DEFINE _D2}
  {$DEFINE _D2orD3}
  {$DEFINE _D2orD3orD4}
{$ENDIF}

{$IFDEF VER100} // Delphi 3
  {$DEFINE _D3}
  {$DEFINE _D3orHigher}
  {$DEFINE _D2orD3}
  {$DEFINE _D2orD3orD4}
  {$DEFINE _D3orD4}
{$ENDIF}

{$IFDEF VER120} // Delphi 4
  {$DEFINE _D3orHigher}
  {$DEFINE _D3orD4}
  {$DEFINE _D4}
  {$DEFINE _D4orHigher}
  {$DEFINE _D2orD3orD4}
  {$IFnDEF KOL_MCK}
    {$DEFINE INPACKAGE}
  {$ENDIF}
{$ENDIF}

{$IFDEF VER130} // Delphi 5
  {$DEFINE _D3orHigher}
  {$DEFINE _D4orHigher}
  {$DEFINE _D5}
  {$DEFINE _D5orHigher}
{$ENDIF}

{--- Delphi 6 and above (use CompilerVersion) ------------------------------}
{$IFDEF CONDITIONALEXPRESSIONS}
  // These version-specific symbols are always true for D6+
  {$DEFINE _D3orHigher}
  {$DEFINE _D4orHigher}
  {$DEFINE _D5orHigher}

  // Define the specific version symbols
  {$IF CompilerVersion = 14}      {$DEFINE _D6}                 {$ENDIF}
  {$IF CompilerVersion = 15}      {$DEFINE _D7}                 {$ENDIF}
  {$IF CompilerVersion = 17}      {$DEFINE _D8}  {$DEFINE _D2005} {$ENDIF} // D2005 (also known as D8 .NET)
  {$IF CompilerVersion = 18}      {$DEFINE _D2006}              {$ENDIF}
  {$IF CompilerVersion = 18.5}    {$DEFINE _D2007}              {$ENDIF}
  {$IF CompilerVersion = 20}      {$DEFINE _D2009}              {$ENDIF}
  {$IF CompilerVersion = 21}      {$DEFINE _D2010}              {$ENDIF}
  {$IF CompilerVersion = 22}      {$DEFINE _DXE}                {$ENDIF}
  {$IF CompilerVersion = 23}      {$DEFINE _DXE2}               {$ENDIF}
  {$IF CompilerVersion = 24}      {$DEFINE _DXE3}               {$ENDIF}
  {$IF CompilerVersion = 25}      {$DEFINE _DXE4}               {$ENDIF}
  {$IF CompilerVersion = 26}      {$DEFINE _DXE5}               {$ENDIF}
  {$IF CompilerVersion = 27}      {$DEFINE _DXE6}               {$ENDIF}
  {$IF CompilerVersion = 28}      {$DEFINE _DXE7}               {$ENDIF}
  {$IF CompilerVersion = 29}      {$DEFINE _DXE8}               {$ENDIF}
  {$IF CompilerVersion = 30}      {$DEFINE _D10}                {$ENDIF}
  {$IF CompilerVersion = 31}      {$DEFINE _D101}               {$ENDIF}
  {$IF CompilerVersion = 32}      {$DEFINE _D102}               {$ENDIF}
  {$IF CompilerVersion = 33}      {$DEFINE _D103}               {$ENDIF}
  {$IF CompilerVersion = 34}      {$DEFINE _D104}               {$ENDIF}
  {$IF CompilerVersion = 35}      {$DEFINE _D11}                {$ENDIF}
  {$IF CompilerVersion = 36}      {$DEFINE _D12}                {$ENDIF}

  // Chain of "orHigher" symbols (cumulative)
  {$IF CompilerVersion >= 14}     {$DEFINE _D6orHigher}        {$ENDIF}
  {$IF CompilerVersion >= 15}     {$DEFINE _D7orHigher}        {$ENDIF}
  {$IF CompilerVersion >= 17}     {$DEFINE _D8orHigher}        {$ENDIF} // same as D2005orHigher
  {$IF CompilerVersion >= 17}     {$DEFINE _D2005orHigher}     {$ENDIF}
  {$IF CompilerVersion >= 18}     {$DEFINE _D2006orHigher}     {$ENDIF}
  {$IF CompilerVersion >= 18.5}   {$DEFINE _D2007orHigher}     {$ENDIF}
  {$IF CompilerVersion >= 20}     {$DEFINE _D2009orHigher}     {$ENDIF}
  {$IF CompilerVersion >= 21}     {$DEFINE _D2010orHigher}     {$ENDIF}
  {$IF CompilerVersion >= 22}     {$DEFINE _DXEorHigher}       {$ENDIF}
  {$IF CompilerVersion >= 23}     {$DEFINE _DXE2orHigher}      {$ENDIF}
  {$IF CompilerVersion >= 24}     {$DEFINE _DXE3orHigher}      {$ENDIF}
  {$IF CompilerVersion >= 25}     {$DEFINE _DXE4orHigher}      {$ENDIF}
  {$IF CompilerVersion >= 26}     {$DEFINE _DXE5orHigher}      {$ENDIF}
  {$IF CompilerVersion >= 27}     {$DEFINE _DXE6orHigher}      {$ENDIF}
  {$IF CompilerVersion >= 28}     {$DEFINE _DXE7orHigher}      {$ENDIF}
  {$IF CompilerVersion >= 29}     {$DEFINE _DXE8orHigher}      {$ENDIF}
  {$IF CompilerVersion >= 30}     {$DEFINE _D10orHigher}       {$ENDIF}
  {$IF CompilerVersion >= 31}     {$DEFINE _D101orHigher}      {$ENDIF}
  {$IF CompilerVersion >= 32}     {$DEFINE _D102orHigher}      {$ENDIF}
  {$IF CompilerVersion >= 33}     {$DEFINE _D103orHigher}      {$ENDIF}
  {$IF CompilerVersion >= 34}     {$DEFINE _D104orHigher}      {$ENDIF}
  {$IF CompilerVersion >= 35}     {$DEFINE _D11orHigher}       {$ENDIF}
  {$IF CompilerVersion >= 36}     {$DEFINE _D12orHigher}       {$ENDIF}

  {--- Warning and compiler settings for D7+ ------------------------------}
  {$IF CompilerVersion >= 15}
    {$WARN UNIT_DEPRECATED OFF}
    {$WARN SYMBOL_PLATFORM OFF}
    {$WARN UNSAFE_TYPE OFF}
    {$WARN UNSAFE_CAST OFF}
    {$WARN UNSAFE_CODE OFF}
  {$ENDIF}

  {--- Delphi 2005+ (D8) : inline off ------------------------------------}
  {$IF CompilerVersion >= 17}
    {$INLINE OFF}
  {$ENDIF}

  {--- Stripping relocations (D2006+) ------------------------------------}
  {$IF CompilerVersion >= 18}
    {$IFNDEF NO_STRIP_RELOC}
      {$SetPEFlags 1}
    {$ENDIF}
  {$ENDIF}

  {--- Platform specific (XE2+ WIN64) ------------------------------------}
  {$IF CompilerVersion >= 23} // XE2
    {$IFDEF WIN64}
      {$DEFINE PAS_VERSION}
      {$DEFINE PAS_ONLY}
      {.$DEFINE UNICODE_CTRLS}
      {$DEFINE STREAM_LARGE64}
      {$DEFINE TMSG_WINDOWS}
    {$ENDIF}
  {$ENDIF}

{$ENDIF} // CONDITIONALEXPRESSIONS

{--- Free Pascal (2.6+) -----------------------------------------------------}
{$IFDEF FPC}
  {$DEFINE PAS_ONLY}
  {$DEFINE USE_OLD_FLAGS} // size of set type in fpc is 4 bytes

  // FPC 2.6 is roughly Delphi 7 level
  {$DEFINE _D3orHigher}
  {$DEFINE _D4orHigher}
  {$DEFINE _D5orHigher}
  {$DEFINE _D6orHigher}
  {$DEFINE _D7}
  {$DEFINE _D7orHigher}

  {$UNDEF ASM_VERSION} // FPC typically uses Pascal only
  {$DEFINE PAS_VERSION}
{$ENDIF FPC}

{--- KOL specific ----------------------------------------------------------}
{$IFNDEF _NOT_KOLCtrlWrapper_}
  {$DEFINE _KOLCtrlWrapper_}
{$ENDIF}

{---- from delphidef.inc ---------------------------------------------------}
{$DEFINE ASM_VERSION} // Comment to produce Pascal code (or add PAS_VERSION)
{$IFDEF ASM_VERSION}
  {$IFDEF PAS_VERSION}
    {$UNDEF ASM_VERSION}
  {$ENDIF}
{$ENDIF}

//{$DEFINE USE_CONSTRUCTORS}   // see comments in original
//{$DEFINE USE_CUSTOMEXTENSIONS}
//{$DEFINE TEST_VERSION}

{$IFNDEF _D6orHigher}
  {$DEFINE PARANOIA}
{$ENDIF}

{$IFNDEF USE_OLD_FLAGS}
  {$DEFINE USE_FLAGS}
{$ELSE}
  {$UNDEF USE_FLAGS}
{$ENDIF}

{$IFnDEF EVENTS_STATIC}
  {$DEFINE EVENTS_DYNAMIC}
{$ENDIF}

{$IFnDEF CMDACTIONS_RECORD}
  {$DEFINE COMMANDACTIONS_OBJ}
  {$DEFINE PACK_COMMANDACTIONS}
  {$IFDEF NOT_PACK_COMMANDACTIONS}
    {$UNDEF PACK_COMMANDACTIONS}
  {$ENDIF}
{$ENDIF}

{$DEFINE KOL3XX}
