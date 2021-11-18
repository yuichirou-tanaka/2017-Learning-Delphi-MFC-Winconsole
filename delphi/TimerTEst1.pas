unit TimerTEst1;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs
  , MMTimer, Vcl.StdCtrls
  ;

type
  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    procedure Button2Click(Sender: TObject);
  private
    { Private êÈåæ }
  public
    { Public êÈåæ }
  end;


  TObjectClass = class
  private
    fTimeOutTimer: TMMTimer;                      //
    nMsgTimeOut: Cardinal;
    nTimeCount: Cardinal;

  procedure _TimeoutTimerTimer(Sender: TObject);

  public
    { Public êÈåæ }
    constructor Create();
  end;


var
  Form1: TForm1;
  gTObjectClass: TObjectClass;
implementation

{$R *.dfm}


constructor TObjectClass.Create();
begin

  if fTimeOutTimer = nil then
  begin
    fTimeOutTimer := TMMTimer.Create(nil);
    fTimeOutTimer.OnTimer := _TimeOutTimerTimer;
    fTimeOutTimer.Delay := 1000;
    fTimeOutTimer.Start;//    fTimeOutTimer.Stop;
  end;
end;


procedure TObjectClass._TimeoutTimerTimer(Sender: TObject);
begin
  Inc(nTimeCount);
end;



procedure TForm1.Button2Click(Sender: TObject);
begin
  if gTObjectClass = nil then
  begin
    gTObjectClass := TObjectClass.Create;
  end;
end;

end.
