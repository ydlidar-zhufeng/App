VERSION 5.00
Object = "{648A5603-2C6E-101B-82B6-000000000014}#1.1#0"; "MSCOMM32.OCX"
Begin VB.Form Form2 
   Caption         =   "Form2"
   ClientHeight    =   5910
   ClientLeft      =   6405
   ClientTop       =   2100
   ClientWidth     =   8730
   LinkTopic       =   "Form2"
   ScaleHeight     =   5910
   ScaleWidth      =   8730
   StartUpPosition =   2  '屏幕中心
   Begin VB.TextBox Text16 
      Height          =   495
      Left            =   3000
      TabIndex        =   33
      Text            =   "0"
      Top             =   4320
      Width           =   735
   End
   Begin VB.TextBox Text15 
      Height          =   495
      Left            =   1680
      TabIndex        =   32
      Text            =   "0"
      Top             =   4320
      Width           =   855
   End
   Begin VB.TextBox Text12 
      Height          =   495
      Left            =   360
      TabIndex        =   31
      Text            =   "0"
      Top             =   4320
      Width           =   735
   End
   Begin VB.TextBox Text14 
      Height          =   495
      Left            =   7200
      TabIndex        =   27
      Text            =   "0"
      Top             =   3000
      Width           =   1215
   End
   Begin VB.TextBox Text13 
      Height          =   495
      Left            =   7200
      TabIndex        =   23
      Text            =   "0"
      Top             =   2400
      Width           =   1215
   End
   Begin VB.TextBox Text11 
      Height          =   495
      Left            =   7200
      TabIndex        =   22
      Text            =   "0"
      Top             =   960
      Width           =   1215
   End
   Begin VB.TextBox Text9 
      Height          =   495
      Left            =   7200
      TabIndex        =   21
      Text            =   "0"
      Top             =   1680
      Width           =   1215
   End
   Begin VB.CommandButton Command3 
      Caption         =   "参数保存00001"
      Height          =   615
      Left            =   7080
      Style           =   1  'Graphical
      TabIndex        =   20
      Top             =   4200
      Width           =   1215
   End
   Begin VB.TextBox Text10 
      Height          =   495
      Left            =   240
      MultiLine       =   -1  'True
      TabIndex        =   19
      Top             =   5160
      Width           =   7575
   End
   Begin VB.Timer Timer1 
      Interval        =   120
      Left            =   1200
      Top             =   240
   End
   Begin MSCommLib.MSComm MSComm1 
      Left            =   480
      Top             =   120
      _ExtentX        =   1005
      _ExtentY        =   1005
      _Version        =   393216
      DTREnable       =   -1  'True
   End
   Begin VB.CommandButton Command2 
      BackColor       =   &H00FF8080&
      Caption         =   "参数下载"
      Height          =   615
      Left            =   5640
      Style           =   1  'Graphical
      TabIndex        =   18
      Top             =   4200
      Width           =   1215
   End
   Begin VB.TextBox Text8 
      Height          =   495
      Left            =   4680
      TabIndex        =   17
      Text            =   "0"
      Top             =   1680
      Width           =   1215
   End
   Begin VB.TextBox Text7 
      Height          =   495
      Left            =   4680
      TabIndex        =   16
      Text            =   "0"
      Top             =   960
      Width           =   1215
   End
   Begin VB.TextBox Text6 
      Height          =   495
      Left            =   4680
      TabIndex        =   13
      Text            =   "0"
      Top             =   3120
      Width           =   1215
   End
   Begin VB.TextBox Text5 
      Height          =   495
      Left            =   4680
      TabIndex        =   12
      Text            =   "0"
      Top             =   2400
      Width           =   1215
   End
   Begin VB.TextBox Text4 
      Height          =   495
      Left            =   1440
      TabIndex        =   11
      Text            =   "0"
      Top             =   3120
      Width           =   1215
   End
   Begin VB.TextBox Text3 
      Height          =   495
      Left            =   1440
      TabIndex        =   10
      Text            =   "0"
      Top             =   2400
      Width           =   1215
   End
   Begin VB.TextBox Text2 
      Height          =   495
      Left            =   1440
      TabIndex        =   9
      Text            =   "0"
      Top             =   1680
      Width           =   1215
   End
   Begin VB.TextBox Text1 
      Height          =   495
      Left            =   1440
      TabIndex        =   8
      Text            =   "0"
      Top             =   960
      Width           =   1215
   End
   Begin VB.CommandButton Command1 
      Caption         =   "返回"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   7680
      TabIndex        =   1
      Top             =   120
      Width           =   855
   End
   Begin VB.Label Label23 
      BackColor       =   &H00FF8080&
      Caption         =   "接收数据显示"
      Height          =   255
      Left            =   7440
      TabIndex        =   41
      Top             =   5640
      Width           =   1215
   End
   Begin VB.Label Label22 
      BackColor       =   &H00FF8080&
      Caption         =   "修改参数后，点击参数下载"
      Height          =   255
      Left            =   5520
      TabIndex        =   40
      Top             =   3840
      Width           =   2295
   End
   Begin VB.Label Label21 
      Caption         =   "2速度-点动方式"
      Height          =   255
      Left            =   3960
      TabIndex        =   39
      Top             =   4920
      Width           =   1335
   End
   Begin VB.Label Label20 
      Caption         =   "1速度-触发方式"
      Height          =   255
      Left            =   3960
      TabIndex        =   38
      Top             =   4560
      Width           =   1335
   End
   Begin VB.Label Label19 
      Caption         =   "0位置运行方式"
      Height          =   255
      Left            =   3960
      TabIndex        =   37
      Top             =   4200
      Width           =   1335
   End
   Begin VB.Label Label18 
      Caption         =   "反转启动信号40079"
      Height          =   375
      Left            =   1560
      TabIndex        =   36
      Top             =   3840
      Width           =   1095
   End
   Begin VB.Label Label17 
      Caption         =   "正转启动信号40078"
      Height          =   375
      Left            =   240
      TabIndex        =   35
      Top             =   3840
      Width           =   1095
   End
   Begin VB.Label Label16 
      Caption         =   "运行方式选择40077"
      Height          =   375
      Left            =   2880
      TabIndex        =   34
      Top             =   3840
      Width           =   1095
   End
   Begin VB.Label Label15 
      Caption         =   "HZ"
      Height          =   375
      Left            =   2760
      TabIndex        =   30
      Top             =   3240
      Width           =   375
   End
   Begin VB.Label Label12 
      Caption         =   "HZ"
      Height          =   255
      Left            =   2760
      TabIndex        =   29
      Top             =   2520
      Width           =   375
   End
   Begin VB.Label Label14 
      Caption         =   "机械零点信号40007"
      Height          =   495
      Left            =   6120
      TabIndex        =   28
      Top             =   3120
      Width           =   1215
   End
   Begin VB.Label Label13 
      Caption         =   "0相对/1绝对40076"
      Height          =   375
      Left            =   6120
      TabIndex        =   26
      Top             =   2520
      Width           =   1095
   End
   Begin VB.Label Label11 
      Caption         =   "波特率40074 40075"
      Height          =   615
      Left            =   6240
      TabIndex        =   25
      Top             =   960
      Width           =   735
   End
   Begin VB.Label Label10 
      Caption         =   "停止模式    (0缓慢停   1立即停）40008"
      Height          =   735
      Left            =   6240
      TabIndex        =   24
      Top             =   1680
      Width           =   1215
   End
   Begin VB.Label Label9 
      Caption         =   "反限位信号40016"
      Height          =   375
      Left            =   3600
      TabIndex        =   15
      Top             =   1800
      Width           =   975
   End
   Begin VB.Label Label8 
      Caption         =   "正限位信号40015"
      Height          =   375
      Left            =   3600
      TabIndex        =   14
      Top             =   1080
      Width           =   975
   End
   Begin VB.Label Label7 
      Caption         =   "往返次数40058"
      Height          =   375
      Left            =   3720
      TabIndex        =   7
      Top             =   3240
      Width           =   735
   End
   Begin VB.Label Label6 
      Caption         =   "螺距40005 40006"
      Height          =   615
      Left            =   3840
      TabIndex        =   6
      Top             =   2400
      Width           =   615
   End
   Begin VB.Label Label5 
      Caption         =   "启动频率40003"
      Height          =   375
      Left            =   480
      TabIndex        =   5
      Top             =   2520
      Width           =   735
   End
   Begin VB.Label Label4 
      Caption         =   "加减频率40004"
      Height          =   375
      Left            =   480
      TabIndex        =   4
      Top             =   3240
      Width           =   735
   End
   Begin VB.Label Label3 
      Caption         =   "步距角40001"
      Height          =   375
      Left            =   600
      TabIndex        =   3
      Top             =   1080
      Width           =   615
   End
   Begin VB.Label Label2 
      Caption         =   "细分40002"
      Height          =   375
      Left            =   600
      TabIndex        =   2
      Top             =   1800
      Width           =   495
   End
   Begin VB.Label Label1 
      Caption         =   "基本参数"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   2640
      TabIndex        =   0
      Top             =   240
      Width           =   1335
   End
End
Attribute VB_Name = "Form2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim zt_flag As Byte
Dim fs_flag As Byte


Private Sub Command1_Click()
    Form2.MSComm1.PortOpen = False
    Unload Form2
    
    Form1.Show
    zt_flag = 0
    interface_flag = 1
End Sub

Private Sub Command2_Click()
    Dim temp0 As Double
    Dim temp1 As Double
    
    Dim temp2 As Integer

    ReDim dat_temp(5) As Long
    
    dat_temp(0) = Val(Text1.Text) * 100 '步距角
    dat_temp(1) = Val(Text2.Text)   '细分
    dat_temp(2) = Val(Text3.Text)   '启动频率
    dat_temp(3) = Val(Text4.Text)   '加减频率
    
    temp0 = Val(Text5.Text) * 100   '螺距
    temp2 = (temp0 \ 65536)         '高16位
    
    dat_temp(5) = temp2                  '高16位
    dat_temp(4) = (temp0 - temp2 * (65536))   '低16位
    
    '''///////以上是把要发送的内容做好
    
    'Call WR_N_REG(1, 0, 6)      '单独测试OK
    zt_flag = 100
    Command2.BackColor = vbRed
End Sub

Private Sub Command3_Click()
    zt_flag = 5
    
    Command3.BackColor = vbRed
End Sub

Private Sub Form_Load()
     
    Form2.MSComm1.CommPort = serial_num   '输入串口号
    Form2.MSComm1.InputLen = 1024
    Form2.MSComm1.Settings = baud
    Form2.MSComm1.InputMode = 1 '1以二进制方式取，0表示文本方式
    Form2.MSComm1.InputLen = 0 '取输入的全部值
    
    Form2.MSComm1.RThreshold = 1
    
    Form2.MSComm1.PortOpen = True
    
    Timer1.Enabled = True
    zt_flag = 0              '一进入界面就读第1条
    fs_flag = 0
End Sub

Private Sub MSComm1_OnComm()
    Dim strbuf As String
    Dim num1 As Byte
    Dim inp() As Byte
    Dim i As Byte
    
    Select Case MSComm1.CommEvent
        '通过取代每一个 case 表达式来处理每个事件与错误
        Case comEvCD               ' CD 线的状态发生变化
        Case comEvCTS              ' CTS 线的状态发生变化
        Case comEvDSR
        Case comEvSend
        Case comEvReceive
            
            strbuf = MSComm1.Input
            inp() = strbuf
            
            If zt_flag = 5 And (inp(0)) = (device_id) And (inp(1)) = 5 Then
                Command3.BackColor = &H8000000F
                zt_flag = 6
            End If

            '//////////////////////////////////////////// 读反馈
            If zt_flag = 0 And fs_flag = 1 And (inp(0)) = (device_id) And (inp(1)) = 3 Then
                
                Text1.Text = cal_2_bs(inp(3), inp(4)) / 100 '(inp(3) * (256) + inp(4)) / 100    '可取2位小数
                Text2.Text = cal_2_bs(inp(5), inp(6))  'inp(5) * (256) + inp(6)
                Text3.Text = cal_2_bs(inp(7), inp(8))  'inp(7) * (256) + inp(8)
                Text4.Text = cal_2_bs(inp(9), inp(10))  'inp(9) * (256) + inp(10)
                Text5.Text = (inp(11) * (256#) + inp(12) + inp(13) * (16777216#) + inp(14) * CDbl(65536)) / 100   '可取2位小数

                zt_flag = 1   '准备读下一条
            End If
            If zt_flag = 1 And fs_flag = 2 And (inp(0)) = (device_id) And (inp(1)) = 3 Then
                
          
                Text7.Text = cal_2_bs(inp(3), inp(4))  'inp(3) * (256) + inp(4)
                Text8.Text = cal_2_bs(inp(5), inp(6))  'inp(5) * (256) + inp(6)

                zt_flag = 2   '准备读下一条
            End If
            If zt_flag = 2 And fs_flag = 3 And (inp(0)) = (device_id) And (inp(1)) = 3 Then
               
                Text6.Text = cal_2_bs(inp(3), inp(4))  'inp(3) * (256) + inp(4)

                zt_flag = 4     '
            End If
            If zt_flag = 4 And fs_flag = 4 And (inp(0)) = (device_id) And (inp(1)) = 3 Then
               
                Text14.Text = cal_2_bs(inp(3), inp(4)) ' inp(3) * (256) + inp(4)
                Text9.Text = cal_2_bs(inp(5), inp(6)) ' inp(5) * (256) + inp(6)

                zt_flag = 200     '
            End If
   
               If zt_flag = 200 And fs_flag = 5 And (inp(0)) = (device_id) And (inp(1)) = 3 Then
               
                Text11.Text = (inp(3) * (256#) + inp(4) + inp(5) * (4294967296#) + inp(6) * CDbl(65536))
                Text13.Text = cal_2_bs(inp(7), inp(8))  'inp(7) * (256) + inp(8)
                
                 Text16.Text = cal_2_bs(inp(9), inp(10))  'inp(9) * (256) + inp(10)
                 Text12.Text = cal_2_bs(inp(11), inp(12))  'inp(11) * (256) + inp(12)
                 Text15.Text = cal_2_bs(inp(13), inp(14))  'inp(13) * (256) + inp(14)

                zt_flag = 201     '读数据完毕
            End If
            
            
            '////////////////////////////////////////////  写反馈
            If zt_flag = 100 And fs_flag = 1 And (inp(0)) = (device_id) And (inp(1)) = &H10 Then
                zt_flag = 101
            End If
            If zt_flag = 101 And fs_flag = 2 And (inp(0)) = (device_id) And (inp(1)) = &H10 Then
                zt_flag = 102
            End If
            If zt_flag = 102 And fs_flag = 3 And (inp(0)) = (device_id) And (inp(1)) = &H6 Then
                'Command2.BackColor = &HFF8080
                zt_flag = 103    '写数据完毕
            End If
            
            If zt_flag = 103 And fs_flag = 4 And (inp(0)) = (device_id) And (inp(1)) = &H10 Then
                zt_flag = 104
            End If
        
            
             If zt_flag = 104 And fs_flag = 5 And (inp(0)) = (device_id) And (inp(1)) = &H10 Then
                Command2.BackColor = &HFF8080
                zt_flag = 105   '写数据完毕
            End If
            
            num1 = UBound(inp)
            For i = 0 To num1
                Text10.Text = Text10.Text & Hex(inp(i))      '将接收到的数据显示在文本框
                Text10.Text = Text10.Text & " "
            Next
        
    End Select
End Sub

Private Sub Text10_Change()
    'Text10.Text = ""
End Sub

Private Sub Text10_Click()
    Text10.Text = ""
End Sub

Private Sub Timer1_Timer()
    If bc_flag = 1 And Second(Now) = 0 Then
         Timer1.Interval = 120
    End If
    
    If zt_flag = 0 Then             '顺序读这几个寄存器
        Form2.MSComm1.RThreshold = 17
        Call RD_N_REG(device_id, 0, 6)
        fs_flag = 1                 '发送了数据的标志     在接收数据的时候判断发的是哪条
    End If
    
    If zt_flag = 1 Then
        Form2.MSComm1.RThreshold = 9
        Call RD_N_REG(device_id, 14, 2)
        fs_flag = 2
    End If
    
    If zt_flag = 2 Then
        Form2.MSComm1.RThreshold = 7
        Call RD_N_REG(device_id, 57, 1)
        fs_flag = 3
    End If
     If zt_flag = 4 Then
        Form2.MSComm1.RThreshold = 9
        Call RD_N_REG(device_id, 6, 2)
        fs_flag = 4
    End If
  
     If zt_flag = 200 Then
        Form2.MSComm1.RThreshold = 17
        Call RD_N_REG(device_id, 73, 6)
        fs_flag = 5
    End If
    
    If zt_flag = 5 Then       ' 保存命令
        Form2.MSComm1.RThreshold = 8
        Call Coil_ON(device_id, 0)
    End If
    
     
    
    
    If zt_flag = 100 Then           '顺序写这几个寄存器
        Form2.MSComm1.RThreshold = 8
        Call WR_N_REG(device_id, 0, 6)
        fs_flag = 1                  '发送了数据的标志     在接收数据的时候判断发的是哪条
    End If
    
    If zt_flag = 101 Then
        ReDim dat_temp(1) As Long
        dat_temp(0) = Val(Text7.Text)           '写正反限位信号
        dat_temp(1) = Val(Text8.Text)
        Form2.MSComm1.RThreshold = 8
        Call WR_N_REG(device_id, 14, 2)
        fs_flag = 2
    End If
    If zt_flag = 102 Then
        Form2.MSComm1.RThreshold = 8
        Call WR_1_REG(device_id, 57, Val(Text6.Text))    '写往返次数
        fs_flag = 3
    End If
    
    If zt_flag = 103 Then
        ReDim dat_temp(1) As Long
        dat_temp(0) = Val(Text14.Text)
        dat_temp(1) = Val(Text9.Text)
        
        Form2.MSComm1.RThreshold = 8
        Call WR_N_REG(device_id, 6, 2)    '写2
        fs_flag = 4
    End If
    If zt_flag = 104 Then
        Dim temp0 As Double
        Dim temp2 As Integer
        ReDim dat_temp(5) As Long
        
        temp0 = Val(Text11.Text)
        temp2 = (temp0 \ 65536)         '高16位
    
        dat_temp(1) = temp2                         '高16位
        dat_temp(0) = (temp0 - temp2 * (65536))     '低16位
    
        dat_temp(2) = Val(Text13.Text)
        
        dat_temp(3) = Val(Text16.Text)
        dat_temp(4) = Val(Text12.Text)
        dat_temp(5) = Val(Text15.Text)
        
        Form2.MSComm1.RThreshold = 8
        Call WR_N_REG(device_id, 73, 6)    '写3
        fs_flag = 5
    End If
    
    
End Sub


