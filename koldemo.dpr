program koldemo;
{$ifdef fpc}{$mode delphi}{$asmmode intel}{$endif}
{$apptype gui}
{$define unicode_ctrls}{$define _D2009orHigher}
uses
  windows,
  kol4;

var
  ident:string;
  Button,panel,memo:PControl;

procedure DoButtonClick(dummy:pointer;sender:pObj);
var
 ExitCode:Integer;
begin
 memo.Clear;
 Applet.SimpleStatusText:='Changed';
end;

begin
  ident := {$ifdef fpc}'Compiled with FreePascal'{$else}'compiled with Delphi'{$endif};
  ident := ident + {$ifdef win64}' for win64'{$else} ' for win32'{$endif};
  ident := ident + {$ifdef unicode_ctrls}' Unicode16'{$else}' Ansi'{$endif};
  Applet:= NewForm (nil, ident);
  Applet.SimpleStatusText:='';
  Applet.Font.ReleaseHandle;
  Applet.Font.AssignHandle(GetStockObject(default_gui_font));
  Memo := NewEditBox(Applet,[eoMultiline]).SetAlign(caClient);
  Memo.Color := clWhite;
  Panel := NewPanel(Applet, esRaised).SetAlign(caBottom);
  Panel.Height := 30;
  Button := NewButton(Panel, 'Test');
  Button.OnClick:=TOnEvent(MakeMethod(Nil,@DoButtonClick));
  Run(Applet);
end.
