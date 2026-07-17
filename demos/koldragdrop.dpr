{
**********************************
*** Drag and Drop Demo for KOL ***
**********************************

This program demonstrates how to drop files dragged from
explorer with KOL.
The example simply displays the filenames and associated Icons
being dropped onto the Applet.
It also shows how to extract Associated Icons and to work with the
ListView Object in Kol.

Note:
I use KOL's standard OnMessage handler, but:
The TWMDropfiles Structure is actually different from TMsg.
But we don't need all parameters so we map
TWMDropFiles.Drop to Tmsg.Wparam.
See messages.pas

Freeware by Thaddy de Koning
}
program koldragdrop;
{$ifdef fpc}{$mode delphi}{$endif}
uses
  Windows,
  ShellApi,
  Messages,
  Kol in '..\kol.pas';

var
  ListView:pControl;
  Images:pImagelist;

function DoDrop(dummy:pointer; var Msg: TMsg; var Rslt: Integer ):Boolean;
var  NumFiles : longint;
  i : longint;  buffer : array[0..255] of char;
  IconIndex:word;
begin
  if msg.Message=WM_DROPFILES then
  begin
    {We are handling this message}
    Result:=true;
    {How many files are being dropped}
    {TWMDropfiles.Drop actually maps to TMsg.Wparam}
    NumFiles := DragQueryFile(Msg.Wparam,DWORD(-1),nil,0);
    {Accept the dropped files}
    for i := 0 to (NumFiles - 1) do
    begin
      DragQueryFile(Msg.Wparam,i,@buffer,sizeof(buffer));
      {Extract the associated Icon and add it to the Imagelist, See WIN32.HLP}
     {$ifdef fpc this will be fixed in the future}
      Images.AddIcon(ExtractAssociatedIcon(hinstance,@Buffer,@IconIndex));
      {$else}
     Images.AddIcon(ExtractAssociatedIcon(hinstance,Buffer,IconIndex));
      {$endif}
      {Add the filename to the Listview and associate the Icon, see KOL docs}
      Listview.lvAdd(ExtractFileName(buffer),i,[],i,i,0);
    end;
  end
  else
    {Make shure the message can be handled elsewhere}
    result:=False;
end;

begin
  {Create Main Form}
  Applet:=NewForm(Nil,'Drop Files from Explorer');

  {Use the Extended WS_EX_ACCEPTFILES Style
  to create a window that accepts drops}
  Applet.ExStyle:=Applet.ExStyle or WS_EX_ACCEPTFILES;

  {Create an Imagelist to store the icons}
  Images:=NewImagelist(Applet);

  {Create an Imagelist in ICON style, and associate it with our imagelist}
  ListView:=NewListView(Applet,lvsIcon,[lvoAutoArrange],nil,images,nil).setalign(caClient);

  {Install a Drop handler:}
  Applet.OnMessage:=TOnMessage(Makemethod(nil,@DoDrop));

  {And run}
  Run(Applet);
end.
