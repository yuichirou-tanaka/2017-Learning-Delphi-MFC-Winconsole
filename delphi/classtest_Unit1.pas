unit Unit1;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, Vcl.ExtCtrls;

type
  TForm1 = class(TForm)
    Memo1: TMemo;
    Image1: TImage;
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
  private
    { Private êÈåæ }
  public
    { Public êÈåæ }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.Button1Click(Sender: TObject);
begin
  Memo1.Lines.LoadFromFile('test1.txt');
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
  Image1.Picture.LoadFromFile('test1.bmp');
end;

procedure TForm1.Button3Click(Sender: TObject);
var
  stringList: TStringList;
begin
  stringList := TStringList.Create;
  try
    stringList.LoadFromFile('test2.txt');
    ShowMessage(stringList.Text);
  finally
    stringList.Free;
  end;
end;

end.
