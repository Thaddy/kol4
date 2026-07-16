program koldemo;
{$ifdef fpc}{$mode delphi}{$asmmode intel}{$endif}
{$apptype gui}
{$define unicode_ctrls}
uses windows,kolnew;
var
  ident:string;
  Button,panel,memo:PControl;
begin
  ident := {$ifdef fpc}'Compiled with fpc'{$else}'compiled with Delphi'{$endif};
  ident := ident + {$ifdef win64}' for win64'{$else} ' for win32'{$endif};
  ident := ident + {$ifdef unicode_ctrls}' Unicode16'{$else}' Ansi'{$endif};
  Applet:= NewForm (nil, ident);
  Applet.Font.ReleaseHandle;
  Applet.Font.AssignHandle(GetStockObject(default_gui_font));
  Memo := NewEditBox(Applet,[eoMultiline]).SetAlign(caClient);
  Memo.Color := clWhite;
  Panel := NewPanel(Applet, esRaised).SetAlign(caBottom);
  Button := NewButton(Panel, 'Test');
  ShowMessage(ident);
  Run(Applet);
end.
