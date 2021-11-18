unit testbounceBall;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls;
type
  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Memo1: TMemo;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
  private
    { Private êÈåæ }
//    Ball: TBall;
  public
    { Public êÈåæ }
    procedure Show(const msg: string);
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

{
procedure TForm1.FormCreate(Sender: TObject);
var
  Temp: array[1..2] of TErasableGraphic;
  i: Integer;
begin
  Temp[1] := TChild1.Create;
  Temp[2] := TChild2.Create;
  for i := 1 to 2 do
  begin
    Temp[i].Test;
    Temp[i].Free;
  end;

end;
}


procedure TForm1.Button1Click(Sender: TObject);
var
  ch: Char;
begin
  ch := 'a';
  //ch.ToUpper;
//  Show(BoolToStr(ch.IsLetter, True));
end;

procedure TForm1.Button2Click(Sender: TObject);
var
  ch: Char;
  str1:string;
begin

  ch := 'a';
  Show(ch);
  Inc(ch,100);
  Show(ch);

  str1 := '';
  for ch := #32 to #1024 do
    str1 := str1 + ch;
  Show(str1);


end;

procedure TForm1.Show(const msg: string);
begin
  Memo1.Lines.Add(msg);
end;

end.
