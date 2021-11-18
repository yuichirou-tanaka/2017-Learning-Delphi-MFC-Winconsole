unit TthreadeventUnit1;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls,SyncObjs;

type

  TMyThread = class(TThread)

      frmPnt:TForm;//親フォームのインスタンス
      constructor Create(frmPnt:TForm);
    private

      //VCLのアクセスはは必ずSynchronize経由でコンポーネントをアクセス
      //する必要があありますがこのメソッド(TThreadMethod)にはパラメータは
      //付けれませんので変数経由でパラメータを渡します
      sync1_aaa:string;

      //このメソッドはDCLアクセス用でsyncronizeで渡される;
      procedure sync1;

    public
      procedure Execute;override;
  end;

   TSleepThread = class(TThread)
  private
    FValue: Integer;
    FLock: TCriticalSection;
  protected
    constructor Create(AValue: Integer; ALock: TCriticalSection);
    procedure Execute; override;
  end;


  // IsMultiThreadが広域変数もあるがこれはTThreadインスタンス作成時に
  //Trueに設定されるので今回は明示的には行わない
  TForm1 = class(TForm)
    Label1: TLabel;
    Memo1: TMemo;
    Button1: TButton;
    procedure Button1Click(Sender: TObject);
  private
    { Private 宣言 }
  public
    { Public 宣言 }
  end;

var
  Form1: TForm1;

implementation
uses
  ActiveX;

{$R *.DFM}


const
  ArrLen = 16;



constructor TSleepThread.Create(AValue: Integer; ALock: TCriticalSection);
begin
  FValue := AValue;
  FLock := ALock;
  inherited Create(False);
end;

procedure TSleepThread.Execute;
begin
  Sleep(1000 * FValue);
  FLock.Acquire;
  Write(FValue:3);
  FLock.Release;
end;


var
  A: array [0 .. ArrLen - 1] of Integer;
  Handles: array [0 .. ArrLen - 1] of THandle;
  Threads: array [0 .. ArrLen - 1] of TThread;
  Lock: TCriticalSection;
  I: Integer;

procedure SleepTest;
begin
  // Generate random data
  for I := 0 to ArrLen - 1 do
  begin
    A[I] := Random(ArrLen - 1);
    Write(A[I]:3);
  end;
  Writeln;

  // Create critical section and threads
  Lock := TCriticalSection.Create;
  for I := 0 to ArrLen - 1 do
  begin
    Threads[I] := TSleepThread.Create(A[I], Lock);
    Handles[I] := Threads[I].Handle;
  end;

  // Wait until threads terminate
  // This may take up to ArrLen - 1 seconds
  WaitForMultipleObjects(ArrLen, @Handles, True, INFINITE);

  // Destroy thread instances
  for I := 0 to ArrLen - 1 do
    Threads[I].Free;
  Lock.Free;

  Writeln;
  Readln;
end;

//**** TMyThread ***

//スレッドコンストラクタ
constructor TMyThread.Create(frmPnt:TForm);
begin
  //基本的なパラメータの授受を行います
  self.frmPnt := frmPnt; //例えば親フォーム
  //今回はスレッドのインスタンス変数も取っていないし自動破棄
  FreeOnTerminate := true;
  //すぐに実行を開始したい場合はFalse;
  inherited Create(false);

end;

//スレッドメイン関数、デーモン化するには無限ループにします
procedure TMyThread.Execute;
var
  i:Integer;
begin
  //ActiveXオブジェクトを利用する場合は必要
  CoInitialize(nil);
  //
  try
    for i := 0 to 10 do begin
      //スレッドでのループ中は必ずこのプロパティを適時監視し
      //Terminateされていないかを検知しきれいに終了
      if terminated then break;
      //sync1用変数作成
      sync1_aaa := IntToStr( i );
      //親フォームのMemoに変数書き込み
      Synchronize(sync1);
      //
      sleep(1000);
    end;

  finally
    //
    CoUninitialize;
  end;
end;

//このメソッドはVCLアクセス用でsyncronizeで渡される
procedure TMyThread.sync1;
begin
  (frmPnt as TForm1).Memo1.Lines.Add( sync1_aaa );
end;

//********* TForm ************
//■ボタンイベント
procedure TForm1.Button1Click(Sender: TObject);

begin
  SleepTest;

  Memo1.Lines.Clear ;

  Memo1.Lines.Add('ok');
  //スレッドの参照が必要ならここで取得しておく
  //今回は生成のみ
  TMyThread.Create(self);

  Memo1.Lines.Add('end');

end;

end.

