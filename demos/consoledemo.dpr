program consoledemo;
{
Demonstrates redirection of console application output
to a Windows GUI program. I needed this for my compiler shell
for Kol, written ofcourse, in kol.
Reminiscent of TurboPascal for Windows.
I use it to spawn things like BCC32, DCC32, BRCC32, TLINK and MAKE.
I Stole it from:

 Martin Lafferty
 martinl@prel.co.uk

See the sourcecode in ConsoleApp.Pas
, I left all original comments.
Thaddy de Koning
}

{$ifdef fpc}{$mode delphi}{$endif}
uses
Kol in '..\kol.pas',
ConsoleApp;
var
  List:pStrlist;
  Panel2,
  Panel,
  Button,
  Button2,
  ExeLabel,
  CmdLabel,
  Exename,
  Command,
  Edit:pControl;


procedure DoNewLine(Dummy:Pointer;Sender:pObj);
{Gets fired for a new line in List}
begin
 Edit.Text:=List.Text;
end;

procedure DoButtonClick(dummy:pointer;sender:pObj);
var
 ExitCode:Integer;
begin
 List.Clear;
 If Command.Text='' then Command.Text:=#32;//seems sometimes necessary
 if FileExists(ExeName.Text) then
   ExitCode:=ExecConsoleApp(Exename.text,Command.text,List,TOnEvent(MakeMethod(nil,@DoNewLine)))
 else
   MsgOk('File not Found');
 Applet.SimpleStatusText:=Pchar('Result from process: '+Int2Str(Exitcode));
end;

begin
  {Main form}
  Applet:=Newform(nil,'Console Redirection');
  Applet.SimplestatusText:='Result from process:';
  Applet.Font.FontHeight:=11;//sets default font for all controls
  List:=NewStrList;

  {Panel for Button'}
  Panel:=NewPanel(Applet,esNone).SetAlign(caTop);
  Button:=NewButton(Panel,'Start');
  Panel.Height:=Button.Height+5;
  Button.OnClick:=TOnEvent(MakeMethod(Nil,@DoButtonClick));

  {Panel for editcontrols}
  Panel2:=NewPanel(Applet,esNone).SetAlign(caTop);
  {Holds executable name and path}
  ExeLabel:=NewLabel(Panel2,'Executable path+name:').SetSize(175,Button.Height).PlaceRight;
  Exename:=NewEditBox(Panel2,[]).SetSize(500,Button.height).PlaceRight;
  ExeName.Text:='c:\program files\borland\delphi4\bin\dcc32.exe';

  {Holds Commandline}
  CmdLabel:=NewLabel(Panel2,'Command Line:').SetSize(175,Button.Height).PlaceDown;
  Command:=NewEditBox(Panel2,[]).SetSize(500,Button.Height).PlaceRight.Resizeparent;;
  Command.Text:='';

  Edit:=NewEditBox(Applet,[eomultiline,eowantreturn]).SetAlign(caClient);
  Edit.Color := clWhite;
  Run(Applet);
  List.Free;
end.

