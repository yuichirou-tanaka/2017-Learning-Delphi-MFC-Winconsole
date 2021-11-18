unit TthreadeventUnit1;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls;

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

  Memo1.Lines.Clear ;

  Memo1.Lines.Add('ok');
  //�X���b�h�̎Q�Ƃ��K�v�Ȃ炱���Ŏ擾���Ă���
  //����͐����̂�
  TMyThread.Create(self);

  Memo1.Lines.Add('end');

end;

end.

