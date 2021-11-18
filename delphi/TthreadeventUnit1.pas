unit TthreadeventUnit1;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls;

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

  Memo1.Lines.Clear ;

  Memo1.Lines.Add('ok');
  //スレッドの参照が必要ならここで取得しておく
  //今回は生成のみ
  TMyThread.Create(self);

  Memo1.Lines.Add('end');

end;

end.

