unit TthreadeventUnit1;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls,SyncObjs;

type

  TMyThread = class(TThread)

      frmPnt:TForm;//�e�t�H�[���̃C���X�^���X
      constructor Create(frmPnt:TForm);
    private

      //VCL�̃A�N�Z�X�͕͂K��Synchronize�o�R�ŃR���|�[�l���g���A�N�Z�X
      //����K�v��������܂������̃��\�b�h(TThreadMethod)�ɂ̓p�����[�^��
      //�t����܂���̂ŕϐ��o�R�Ńp�����[�^��n���܂�
      sync1_aaa:string;

      //���̃��\�b�h��DCL�A�N�Z�X�p��syncronize�œn�����;
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


  // IsMultiThread���L��ϐ������邪�����TThread�C���X�^���X�쐬����
  //True�ɐݒ肳���̂ō���͖����I�ɂ͍s��Ȃ�
  TForm1 = class(TForm)
    Label1: TLabel;
    Memo1: TMemo;
    Button1: TButton;
    procedure Button1Click(Sender: TObject);
  private
    { Private �錾 }
  public
    { Public �錾 }
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

//�X���b�h�R���X�g���N�^
constructor TMyThread.Create(frmPnt:TForm);
begin
  //��{�I�ȃp�����[�^�̎�����s���܂�
  self.frmPnt := frmPnt; //�Ⴆ�ΐe�t�H�[��
  //����̓X���b�h�̃C���X�^���X�ϐ�������Ă��Ȃ��������j��
  FreeOnTerminate := true;
  //�����Ɏ��s���J�n�������ꍇ��False;
  inherited Create(false);

end;

//�X���b�h���C���֐��A�f�[����������ɂ͖������[�v�ɂ��܂�
procedure TMyThread.Execute;
var
  i:Integer;
begin
  //ActiveX�I�u�W�F�N�g�𗘗p����ꍇ�͕K�v
  CoInitialize(nil);
  //
  try
    for i := 0 to 10 do begin
      //�X���b�h�ł̃��[�v���͕K�����̃v���p�e�B��K���Ď���
      //Terminate����Ă��Ȃ��������m�����ꂢ�ɏI��
      if terminated then break;
      //sync1�p�ϐ��쐬
      sync1_aaa := IntToStr( i );
      //�e�t�H�[����Memo�ɕϐ���������
      Synchronize(sync1);
      //
      sleep(1000);
    end;

  finally
    //
    CoUninitialize;
  end;
end;

//���̃��\�b�h��VCL�A�N�Z�X�p��syncronize�œn�����
procedure TMyThread.sync1;
begin
  (frmPnt as TForm1).Memo1.Lines.Add( sync1_aaa );
end;

//********* TForm ************
//���{�^���C�x���g
procedure TForm1.Button1Click(Sender: TObject);

begin
  SleepTest;

  Memo1.Lines.Clear ;

  Memo1.Lines.Add('ok');
  //�X���b�h�̎Q�Ƃ��K�v�Ȃ炱���Ŏ擾���Ă���
  //����͐����̂�
  TMyThread.Create(self);

  Memo1.Lines.Add('end');

end;

end.

