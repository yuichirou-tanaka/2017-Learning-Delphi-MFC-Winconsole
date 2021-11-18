unit canvastestunit;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls;

type

  TestProp = class
  private
    fsysnamelog: string;
    function GetSysNameLog: string;
    procedure SetSysNameLog(const Value: string);
  public
    property SysNameLog: string read GetSysNameLog write SetSysNameLog ;            // ÉfÅ[É^Getter
  end;

  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Edit1: TEdit;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
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
var
  tmpX1, tmpY1 : Integer;
begin
  tmpX1 := 812;
  tmpY1 := 526;

  Canvas.Pen.Color := $FF00FF;
  //Canvas.Pen.Width := Canvas.Pen.Width * 2;
  Canvas.Pen.Style := psDOT;
  Canvas.Pen.Width := 1;

//  Canvas.MoveTo(0,0);
  Canvas.MoveTo(444,549);

//  Canvas.LineTo(812,526);

  Canvas.LineTo(513,561);
  Canvas.LineTo(402, 735);

  Canvas.Ellipse(tmpX1 - 3, tmpY1 - 3, tmpX1 + 3, tmpY1 + 3);



//

end;

{ TestProp }

function TestProp.GetSysNameLog: string;
begin
  Result := fsysnamelog;
end;

procedure TestProp.SetSysNameLog(const Value: string);
begin
  fsysnamelog := Value;
end;

procedure TForm1.Button2Click(Sender: TObject);
var
  fTestProp: TestProp;
begin
  fTestProp := TestProp.Create;
  fTestProp.SysNameLog := 'test';
  Edit1.Text :=fTestProp.SysNameLog;
end;

end.
