VERSION 5.00
Object = "{648A5603-2C6E-101B-82B6-000000000014}#1.1#0"; "MSCOMM32.OCX"
Begin VB.Form Form4 
   Caption         =   "Form4"
   ClientHeight    =   7605
   ClientLeft      =   5940
   ClientTop       =   2100
   ClientWidth     =   10080
   LinkTopic       =   "Form4"
   ScaleHeight     =   7605
   ScaleWidth      =   10080
   StartUpPosition =   2  '屏幕中心
   Begin VB.CommandButton Command7 
      Caption         =   "参数下载"
      Height          =   615
      Left            =   7920
      Style           =   1  'Graphical
      TabIndex        =   45
      Top             =   6840
      Visible         =   0   'False
      Width           =   1695
   End
   Begin VB.CommandButton Command6 
      Caption         =   "工程清零00003"
      Height          =   615
      Left            =   7920
      Style           =   1  'Graphical
      TabIndex        =   44
      Top             =   4320
      Width           =   1095
   End
   Begin VB.CommandButton Command5 
      Caption         =   "参数保存00001"
      Height          =   615
      Left            =   7920
      Style           =   1  'Graphical
      TabIndex        =   43
      Top             =   2400
      Width           =   1095
   End
   Begin VB.CommandButton Command4 
      Caption         =   "工程读取00002"
      Height          =   615
      Left            =   7920
      Style           =   1  'Graphical
      TabIndex        =   42
      Top             =   3360
      Width           =   1095
   End
   Begin VB.CommandButton Command3 
      Caption         =   "下一步00019"
      Height          =   495
      Left            =   4680
      TabIndex        =   41
      Top             =   1800
      Width           =   975
   End
   Begin VB.CommandButton Command2 
      Caption         =   "上一步00018"
      Height          =   495
      Left            =   3480
      TabIndex        =   40
      Top             =   1800
      Width           =   975
   End
   Begin VB.TextBox Text16 
      Height          =   495
      Left            =   5160
      TabIndex        =   31
      Text            =   "0"
      Top             =   5400
      Width           =   855
   End
   Begin VB.TextBox Text15 
      Height          =   495
      Left            =   5160
      TabIndex        =   30
      Text            =   "0"
      Top             =   4680
      Width           =   855
   End
   Begin VB.TextBox Text14 
      Height          =   495
      Left            =   1200
      TabIndex        =   27
      Text            =   "0"
      Top             =   5400
      Width           =   855
   End
   Begin VB.TextBox Text13 
      Height          =   495
      Left            =   5160
      TabIndex        =   26
      Text            =   "0"
      Top             =   3960
      Width           =   855
   End
   Begin VB.TextBox Text12 
      Height          =   495
      Left            =   1560
      TabIndex        =   13
      Text            =   "1"
      Top             =   6840
      Width           =   855
   End
   Begin VB.TextBox Text11 
      Height          =   495
      Left            =   4080
      TabIndex        =   12
      Text            =   "0"
      Top             =   6120
      Width           =   855
   End
   Begin VB.TextBox Text10 
      Height          =   495
      Left            =   2400
      TabIndex        =   11
      Text            =   "0"
      Top             =   6120
      Width           =   855
   End
   Begin VB.TextBox Text9 
      Height          =   495
      Left            =   720
      TabIndex        =   10
      Text            =   "0"
      Top             =   6120
      Width           =   855
   End
   Begin VB.TextBox Text8 
      Height          =   495
      Left            =   1200
      TabIndex        =   9
      Text            =   "0"
      Top             =   4680
      Width           =   855
   End
   Begin VB.TextBox Text7 
      Height          =   495
      Left            =   1200
      TabIndex        =   8
      Text            =   "0"
      Top             =   3960
      Width           =   855
   End
   Begin VB.TextBox Text6 
      Height          =   495
      Left            =   5160
      TabIndex        =   7
      Text            =   "0"
      Top             =   3240
      Width           =   855
   End
   Begin VB.TextBox Text5 
      Height          =   495
      Left            =   1200
      TabIndex        =   6
      Text            =   "0"
      Top             =   3240
      Width           =   855
   End
   Begin VB.TextBox Text4 
      Height          =   495
      Left            =   1200
      TabIndex        =   5
      Text            =   "0"
      Top             =   2520
      Width           =   855
   End
   Begin VB.TextBox Text3 
      Height          =   495
      Left            =   1200
      TabIndex        =   4
      Text            =   "1"
      Top             =   1800
      Width           =   855
   End
   Begin VB.TextBox Text2 
      Height          =   495
      Left            =   3600
      TabIndex        =   3
      Text            =   "1"
      Top             =   1080
      Width           =   855
   End
   Begin VB.TextBox Text1 
      Height          =   495
      Left            =   1200
      TabIndex        =   2
      Text            =   "1"
      Top             =   1080
      Width           =   855
   End
   Begin VB.Timer Timer1 
      Interval        =   100
      Left            =   7800
      Top             =   240
   End
   Begin MSCommLib.MSComm MSComm1 
      Left            =   6960
      Top             =   120
      _ExtentX        =   1005
      _ExtentY        =   1005
      _Version        =   393216
      DTREnable       =   -1  'True
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
      Left            =   9000
      TabIndex        =   0
      Top             =   120
      Width           =   855
   End
   Begin VB.Label Label34 
      BackColor       =   &H00FF8080&
      Caption         =   "若工程循环次数为0，则工程无限循环"
      Height          =   255
      Left            =   3120
      TabIndex        =   56
      Top             =   6960
      Width           =   3135
   End
   Begin VB.Label Label33 
      BackColor       =   &H00FF8080&
      Caption         =   "修改工程参数后，点击参数保存"
      Height          =   255
      Left            =   7200
      TabIndex        =   55
      Top             =   2040
      Width           =   2535
   End
   Begin VB.Label Label32 
      Caption         =   "工程号若显示为0，参数保存会不成功"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   10.5
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   255
      Left            =   120
      TabIndex        =   54
      Top             =   600
      Width           =   3855
   End
   Begin VB.Label Label31 
      Caption         =   "注意：工程号必须为1，总步数最大33"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   10.5
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   255
      Left            =   120
      TabIndex        =   53
      Top             =   240
      Width           =   3855
   End
   Begin VB.Label Label30 
      Caption         =   "2、再分别设定第1步，第2步，第N步的参数。"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   10.5
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   255
      Left            =   5880
      TabIndex        =   52
      Top             =   1440
      Width           =   4335
   End
   Begin VB.Label Label29 
      Caption         =   "工程设置步骤：1、工程号默认为1， 然后设定工程总步数，"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   10.5
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   255
      Left            =   4560
      TabIndex        =   51
      Top             =   1080
      Width           =   5415
   End
   Begin VB.Label Label28 
      BackColor       =   &H00FFC0C0&
      Caption         =   "0表示无设置    1表示OC1开     2表示OC1关      依次类推，最大值8"
      Height          =   735
      Left            =   6120
      TabIndex        =   50
      Top             =   4560
      Width           =   1575
   End
   Begin VB.Label Label27 
      Caption         =   "HZ"
      Height          =   255
      Left            =   2160
      TabIndex        =   49
      Top             =   4800
      Width           =   375
   End
   Begin VB.Label Label26 
      Caption         =   "HZ"
      Height          =   255
      Left            =   2160
      TabIndex        =   48
      Top             =   4080
      Width           =   495
   End
   Begin VB.Label Label25 
      Caption         =   "(0正向，1反向)"
      Height          =   255
      Left            =   2160
      TabIndex        =   47
      Top             =   5520
      Width           =   1335
   End
   Begin VB.Label Label24 
      Caption         =   "毫秒"
      Height          =   255
      Left            =   6120
      TabIndex        =   46
      Top             =   5520
      Width           =   495
   End
   Begin VB.Label Label23 
      Caption         =   "次"
      Height          =   375
      Left            =   2520
      TabIndex        =   39
      Top             =   6960
      Width           =   495
   End
   Begin VB.Label Label22 
      Caption         =   "工程循环40050"
      Height          =   375
      Left            =   240
      TabIndex        =   38
      Top             =   6960
      Width           =   1095
   End
   Begin VB.Label Label21 
      Caption         =   "次"
      Height          =   375
      Left            =   5040
      TabIndex        =   37
      Top             =   6240
      Width           =   495
   End
   Begin VB.Label Label20 
      Caption         =   "步循环40039"
      Height          =   375
      Left            =   3480
      TabIndex        =   36
      Top             =   6240
      Width           =   615
   End
   Begin VB.Label Label19 
      Caption         =   "步到第40038"
      Height          =   375
      Left            =   1680
      TabIndex        =   35
      Top             =   6120
      Width           =   615
   End
   Begin VB.Label Label18 
      Caption         =   "从第40037"
      Height          =   375
      Left            =   120
      TabIndex        =   34
      Top             =   6120
      Width           =   495
   End
   Begin VB.Label Label17 
      Caption         =   "本步运行完延时40035 40036"
      Height          =   375
      Left            =   3840
      TabIndex        =   33
      Top             =   5520
      Width           =   1335
   End
   Begin VB.Label Label16 
      Caption         =   "输出开/关40034"
      Height          =   375
      Left            =   4200
      TabIndex        =   32
      Top             =   4800
      Width           =   975
   End
   Begin VB.Label Label15 
      Caption         =   "运行方向40030"
      Height          =   375
      Left            =   240
      TabIndex        =   29
      Top             =   5520
      Width           =   735
   End
   Begin VB.Label Label14 
      Caption         =   "加减频率40029"
      Height          =   375
      Left            =   240
      TabIndex        =   28
      Top             =   4800
      Width           =   855
   End
   Begin VB.Label Label13 
      Caption         =   "距离40032 40033"
      Height          =   615
      Left            =   4560
      TabIndex        =   25
      Top             =   3960
      Width           =   615
   End
   Begin VB.Label Label12 
      Caption         =   "启动频率40028"
      Height          =   375
      Left            =   240
      TabIndex        =   24
      Top             =   4080
      Width           =   735
   End
   Begin VB.Label Label11 
      Caption         =   "RPM"
      Height          =   255
      Left            =   6240
      TabIndex        =   23
      Top             =   3360
      Width           =   495
   End
   Begin VB.Label Label10 
      Caption         =   "速度40031"
      Height          =   375
      Left            =   4560
      TabIndex        =   22
      Top             =   3360
      Width           =   495
   End
   Begin VB.Label Label9 
      Caption         =   "有效则启动本步，"
      Height          =   375
      Left            =   2160
      TabIndex        =   21
      Top             =   3360
      Width           =   1455
   End
   Begin VB.Label Label8 
      Caption         =   "有效则停止本步，进入下一步"
      Height          =   375
      Left            =   2160
      TabIndex        =   20
      Top             =   2640
      Width           =   2415
   End
   Begin VB.Label Label7 
      Caption         =   "若输入40027"
      Height          =   375
      Left            =   240
      TabIndex        =   19
      Top             =   3360
      Width           =   855
   End
   Begin VB.Label Label6 
      Caption         =   "若输入40051"
      Height          =   375
      Left            =   240
      TabIndex        =   18
      Top             =   2520
      Width           =   855
   End
   Begin VB.Label Label5 
      Caption         =   "步的参数"
      Height          =   375
      Left            =   2160
      TabIndex        =   17
      Top             =   1920
      Width           =   855
   End
   Begin VB.Label Label4 
      Caption         =   "设定第40040"
      Height          =   375
      Left            =   240
      TabIndex        =   16
      Top             =   1920
      Width           =   855
   End
   Begin VB.Label Label3 
      Caption         =   "设定工程总步数40026"
      Height          =   375
      Left            =   2280
      TabIndex        =   15
      Top             =   1080
      Width           =   1335
   End
   Begin VB.Label Label2 
      Caption         =   "设定工程号40025"
      Height          =   375
      Left            =   240
      TabIndex        =   14
      Top             =   1080
      Width           =   975
   End
   Begin VB.Label Label1 
      Caption         =   "工程参数界面"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   14.25
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   4320
      TabIndex        =   1
      Top             =   120
      Width           =   1935
   End
End
Attribute VB_Name = "Form4"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim zt_flag As Byte
Dim fs_flag As Byte

 

Private Sub Command1_Click()
    Form4.MSComm1.PortOpen = False
    Unload Form4
    
    Form1.Show
End Sub

Private Sub Command2_Click()
    zt_flag = 33             '2种方法都可以
    'Text3.Text = Text3.Text - 1
End Sub

Private Sub Command3_Click()
    zt_flag = 34
    'Text3.Text = Text3.Text + 1
End Sub

Private Sub Command4_Click()
    zt_flag = 30
     Command4.BackColor = vbRed
End Sub

Private Sub Command5_Click()
    zt_flag = 31
    Command5.BackColor = vbRed
End Sub

Private Sub Command6_Click()
    zt_flag = 32
    Command6.BackColor = vbRed
End Sub

Private Sub Command7_Click()          '写数据--工程号不用写    这个没用到
    Dim temp0 As Double
    Dim temp1 As Double

    Dim temp2 As Integer

    ReDim dat_temp(9) As Long

    dat_temp(0) = Val(Text1.Text)
    dat_temp(1) = Val(Text2.Text)
    dat_temp(2) = Val(Text5.Text)
    dat_temp(3) = Val(Text7.Text)
    dat_temp(4) = Val(Text8.Text)
    dat_temp(5) = Val(Text14.Text)
    dat_temp(6) = Val(Text6.Text)

    temp0 = Val(Text13.Text) * 100  '距离
    temp2 = (temp0 \ 65536)         '高16位
    dat_temp(8) = temp2                     '高16位
    dat_temp(7) = (temp0 - temp2 * (65536)) '低16位

    dat_temp(9) = Val(Text15.Text)

    zt_flag = 100
    Command7.BackColor = vbRed
End Sub

Private Sub Form_Load()
    Form4.MSComm1.CommPort = serial_num   '输入串口号
    Form4.MSComm1.InputLen = 1024
    Form4.MSComm1.Settings = baud
    Form4.MSComm1.InputMode = 1 '1以二进制方式取，0表示文本方式
    Form4.MSComm1.InputLen = 0 '取输入的全部值
    
    Form4.MSComm1.RThreshold = 1
    
    Form4.MSComm1.PortOpen = True
    
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
            
            '''''线圈操作反馈
            If zt_flag = 33 And (inp(0)) = (device_id) And (inp(1)) = 5 Then
                zt_flag = 0     ''''''上一页
             End If
             If zt_flag = 34 And (inp(0)) = (device_id) And (inp(1)) = 5 Then
                zt_flag = 0     ''''''下一页
             End If
            
            
            '''修改完参数之后，，重新读取本界面参数
            If zt_flag = 9 And (inp(0)) = (device_id) And (inp(1)) = 6 Then
                zt_flag = 0     ''''''修改设定第几步参数之后， 重新读本界面参数
                fs_flag = 0
             End If
             If zt_flag = 10 And (inp(0)) = (device_id) And (inp(1)) = 6 Then
                zt_flag = 0     ''''''修改设定第几步参数之后， 重新读本界面参数
                fs_flag = 0
             End If
     
             If zt_flag = 40 And (inp(0)) = (device_id) And (inp(1)) = 5 Then   '读取
                zt_flag = 0     ''''''
                fs_flag = 0
                Command4.BackColor = &H8000000F
                Timer1.Interval = 500
             End If
             If zt_flag = 41 And (inp(0)) = (device_id) And (inp(1)) = 5 Then  '保存
                zt_flag = 51
                Command5.BackColor = &H8000000F
                'Timer1.Interval = 1000
             End If
             If zt_flag = 42 And (inp(0)) = (device_id) And (inp(1)) = 5 Then   '清零
                zt_flag = 0
                fs_flag = 0
                Command6.BackColor = &H8000000F ''''''
                Timer1.Interval = 600
             End If
             
             
            '//////////////////////////////////////////// 读反馈
            If zt_flag = 0 And fs_flag = 1 And (inp(0)) = (device_id) And (inp(1)) = 3 Then
                
                Text1.Text = cal_2_bs(inp(3), inp(4))  '(inp(3) * (256) + inp(4))  '工程号
                Text2.Text = cal_2_bs(inp(5), inp(6))  '(inp(5) * (256) + inp(6))  '工程总步数
                Text5.Text = cal_2_bs(inp(7), inp(8))  '(inp(7) * (256) + inp(8))  '启动口
                Text7.Text = cal_2_bs(inp(9), inp(10))  '(inp(9) * (256) + inp(10)) '启动频率
                Text8.Text = cal_2_bs(inp(11), inp(12))  '(inp(11) * (256) + inp(12)) '加减频率
                Text14.Text = cal_2_bs(inp(13), inp(14)) ' (inp(13) * (256) + inp(14)) '方向
                Text6.Text = cal_2_bs(inp(15), inp(16))  '(inp(15) * (256) + inp(16)) '速度
                Text13.Text = (inp(17) * (256#) + inp(18) + inp(19) * (16777216#) + inp(20) * CDbl(65536)) / 100   '可取2位小数
                Text15.Text = cal_2_bs(inp(21), inp(22)) ' (inp(21) * (256) + inp(22)) '输出口
 
                zt_flag = 1   '准备读下一条
    
            End If
            If zt_flag = 1 And fs_flag = 2 And (inp(0)) = (device_id) And (inp(1)) = 3 Then
                Text16.Text = (inp(3) * (256#) + inp(4) + inp(5) * (16777216#) + inp(6) * CDbl(65536))
                Text9.Text = cal_2_bs(inp(7), inp(8))  '(inp(7) * (256) + inp(8)) '段起始
                Text10.Text = cal_2_bs(inp(9), inp(10)) ' (inp(9) * (256) + inp(10)) '段结束
                Text11.Text = cal_2_bs(inp(11), inp(12)) ' (inp(11) * (256) + inp(12)) '段次数
                Text3.Text = cal_2_bs(inp(13), inp(14)) ' (inp(13) * (256) + inp(14)) '当前步号设置
                
                zt_flag = 2   '准备读下一条
              
            End If
            If zt_flag = 2 And fs_flag = 3 And (inp(0)) = (device_id) And (inp(1)) = 3 Then
                Text12.Text = cal_2_bs(inp(3), inp(4))  '(inp(3) * (256) + inp(4)) '循环次数
                Text4.Text = cal_2_bs(inp(5), inp(6)) ' (inp(5) * (256) + inp(6)) '停止口
                
                zt_flag = 3  '读完毕
                Timer1.Interval = 100
            End If
            
            
            
            
            '////////////////////////////////////////////  写反馈
            If zt_flag = 101 And fs_flag = 1 And (inp(0)) = (device_id) And (inp(1)) = &H10 Then
                zt_flag = 102
            End If
            If zt_flag = 103 And fs_flag = 2 And (inp(0)) = (device_id) And (inp(1)) = &H10 Then
                zt_flag = 104
            End If
            If zt_flag = 105 And fs_flag = 3 And (inp(0)) = (device_id) And (inp(1)) = &H10 Then
                zt_flag = 106                      '写数据完毕
                Command7.BackColor = &H8000000F
            End If
        
    End Select
End Sub

Private Sub Text1_Change()
     
    If zt_flag = 8 Then
    zt_flag = 9
    End If
End Sub

Private Sub Text1_Click()
    zt_flag = 8
End Sub

Private Sub Text10_Change()
    If zt_flag = 73 Then
    zt_flag = 22
    End If
End Sub

Private Sub Text10_Click()
    zt_flag = 73
End Sub

Private Sub Text11_Change()
    If zt_flag = 74 Then
    zt_flag = 23
    End If
End Sub

Private Sub Text11_Click()
    zt_flag = 74
End Sub

Private Sub Text12_Change()
    If zt_flag = 75 Then
    zt_flag = 24
    End If
End Sub

Private Sub Text12_Click()
    zt_flag = 75
End Sub

Private Sub Text13_Change()
    If zt_flag = 67 Then
    zt_flag = 18
    End If
End Sub

Private Sub Text13_Click()
    zt_flag = 67
End Sub

Private Sub Text14_Change()
    If zt_flag = 70 Then
    zt_flag = 16
    End If
End Sub

Private Sub Text14_Click()
    zt_flag = 70
End Sub

Private Sub Text15_Change()
    If zt_flag = 69 Then
    zt_flag = 19
    End If
End Sub

Private Sub Text15_Click()
    zt_flag = 69
End Sub

Private Sub Text16_Change()
    If zt_flag = 71 Then
    zt_flag = 20
    End If
End Sub

Private Sub Text16_Click()
    zt_flag = 71
End Sub

Private Sub Text2_Change()
    If zt_flag = 61 Then
    If Val(Text2.Text) < Val(Text3.Text) Then
        MsgBox "总步数不能小于当前步,请重新设置"
    ElseIf Val(Text2.Text) = 0 Then
        MsgBox "总步数不能为0,请重新设置"
    Else
        zt_flag = 11
    End If
    End If
End Sub

Private Sub Text2_Click()
    zt_flag = 61
End Sub

Private Sub Text3_Change()
    If zt_flag = 62 Then
    If Val(Text3.Text) > Val(Text2.Text) Then
        MsgBox "当前步不能大于总步数，请重新设置"
    ElseIf Val(Text3.Text) < 1 Then
        MsgBox "当前步不能小于1，请重新设置"
    Else
        zt_flag = 10
    End If
    End If
    
End Sub

Private Sub Text3_Click()
    zt_flag = 62
End Sub

Private Sub Text4_Change()
    If zt_flag = 63 Then
    zt_flag = 12
    End If
End Sub

Private Sub Text4_Click()
    zt_flag = 63
End Sub

Private Sub Text5_Change()
    If zt_flag = 64 Then
    zt_flag = 13
    End If
End Sub

Private Sub Text5_Click()
    zt_flag = 64
End Sub

Private Sub Text6_Change()
    If zt_flag = 65 Then
    zt_flag = 17
    End If
End Sub

Private Sub Text6_Click()
    zt_flag = 65
End Sub

Private Sub Text7_Change()
    If zt_flag = 66 Then
    zt_flag = 14
    End If
End Sub

Private Sub Text7_Click()
    zt_flag = 66
End Sub

Private Sub Text8_Change()
    If zt_flag = 68 Then
    zt_flag = 15
    End If
End Sub

Private Sub Text8_Click()
    zt_flag = 68
End Sub

Private Sub Text9_Change()
    If zt_flag = 72 Then
    zt_flag = 21
    End If
End Sub

Private Sub Text9_Click()
    zt_flag = 72
End Sub

Private Sub Timer1_Timer()
    Dim temp0 As Double
    Dim temp2 As Integer
    
     If zt_flag = 52 Then        ' 保存后延时完一段时间后   才可以再去读
         Timer1.Interval = 100
         zt_flag = 0     ''''''
         fs_flag = 0
    End If
    If zt_flag = 51 Then        ' 保存后延时完一段时间后   才可以再去读
         zt_flag = 52
    End If
    
    If zt_flag = 30 Then        '工程读取
        Form4.MSComm1.RThreshold = 8
        Call Coil_ON(device_id, 1)
        zt_flag = 40
    End If
    If zt_flag = 31 Then        '工程保存
        Form4.MSComm1.RThreshold = 8
        Call Coil_ON(device_id, 0)
        zt_flag = 41
        Timer1.Interval = 1000   ''''''''''''''''''''''''
    End If
    If zt_flag = 32 Then        '工程清零
        Form4.MSComm1.RThreshold = 8
        Call Coil_ON(device_id, 2)
         zt_flag = 42
    End If
    If zt_flag = 33 Then        '上一步
        Form4.MSComm1.RThreshold = 8
        Call Coil_ON(device_id, 17)
    End If
    If zt_flag = 34 Then        '下一步
        Form4.MSComm1.RThreshold = 8
         Call Coil_ON(device_id, 18)
    End If
    
        
    ''''''第2步   分别设置工程总步数和当前步数
    If zt_flag = 9 Then        '设定工程号     然后重新读取当前界面参数
    
        Form4.MSComm1.RThreshold = 8
        Call WR_1_REG(device_id, 24, Val(Text1.Text))
    End If
    If zt_flag = 10 Then        '设定当前步号      然后重新读取当前界面参数
        Form4.MSComm1.RThreshold = 8
        Call WR_1_REG(device_id, 39, Val(Text3.Text))
    End If
    If zt_flag = 11 Then        '设定工程总步数      然后重新读取当前界面参数
        Form4.MSComm1.RThreshold = 8
        Call WR_1_REG(device_id, 25, Val(Text2.Text))
    End If
    If zt_flag = 12 Then        '设定停止口      然后重新读取当前界面参数
        Form4.MSComm1.RThreshold = 8
        Call WR_1_REG(device_id, 50, Val(Text4.Text))
    End If
    If zt_flag = 13 Then        '设定启动口      然后重新读取当前界面参数
        Form4.MSComm1.RThreshold = 8
        Call WR_1_REG(device_id, 26, Val(Text5.Text))
    End If
    If zt_flag = 14 Then        '设定启动频率      然后重新读取当前界面参数
        Form4.MSComm1.RThreshold = 8
        Call WR_1_REG(device_id, 27, Val(Text7.Text))
    End If
    If zt_flag = 15 Then        '设定加减频率      然后重新读取当前界面参数
        Form4.MSComm1.RThreshold = 8
        Call WR_1_REG(device_id, 28, Val(Text8.Text))
    End If
    If zt_flag = 16 Then        '设定方向      然后重新读取当前界面参数
        Form4.MSComm1.RThreshold = 8
        Call WR_1_REG(device_id, 29, Val(Text14.Text))
    End If
    If zt_flag = 17 Then        '设定速度      然后重新读取当前界面参数
        Form4.MSComm1.RThreshold = 8
        Call WR_1_REG(device_id, 30, Val(Text6.Text))
    End If
    If zt_flag = 18 Then        '设定距离      然后重新读取当前界面参数
        ReDim dat_temp(1) As Long
        temp0 = Val(Text13.Text) * 100
        temp2 = (temp0 \ 65536)

        dat_temp(1) = temp2                     '高16位
        dat_temp(0) = (temp0 - temp2 * (65536)) '低16位
        Form4.MSComm1.RThreshold = 8
        Call WR_N_REG(device_id, 31, 2)
    End If
    If zt_flag = 19 Then        '设定输出      然后重新读取当前界面参数
        Form4.MSComm1.RThreshold = 8
        Call WR_1_REG(device_id, 33, Val(Text15.Text))
    End If
    If zt_flag = 20 Then        '设定延时      然后重新读取当前界面参数
        ReDim dat_temp(1) As Long
        temp0 = Val(Text16.Text)
        temp2 = (temp0 \ 65536)

        dat_temp(1) = temp2                     '高16位
        dat_temp(0) = (temp0 - temp2 * (65536)) '低16位
        Form4.MSComm1.RThreshold = 8
        Call WR_N_REG(device_id, 34, 2)
    End If
    If zt_flag = 21 Then        '设定段起始      然后重新读取当前界面参数
        Form4.MSComm1.RThreshold = 8
        Call WR_1_REG(device_id, 36, Val(Text9.Text))
    End If
    If zt_flag = 22 Then        '设定段结束      然后重新读取当前界面参数
        Form4.MSComm1.RThreshold = 8
        Call WR_1_REG(device_id, 37, Val(Text10.Text))
    End If
    If zt_flag = 23 Then        '设定段循环次数      然后重新读取当前界面参数
        Form4.MSComm1.RThreshold = 8
        Call WR_1_REG(device_id, 38, Val(Text11.Text))
    End If
    If zt_flag = 24 Then        '设定工程循环次数      然后重新读取当前界面参数
        Form4.MSComm1.RThreshold = 8
        Call WR_1_REG(device_id, 49, Val(Text12.Text))
    End If
    
    

    ''''''第1步   读本界面的所有参数
    If zt_flag = 0 Then   '读10个寄存器
        Form4.MSComm1.RThreshold = 25
        Call RD_N_REG(device_id, 24, 10)
        fs_flag = 1                 '发送了数据的标志     在接收数据的时候判断发的是哪条
    End If
    If zt_flag = 1 Then     '读6个寄存器
        Form4.MSComm1.RThreshold = 17
        Call RD_N_REG(device_id, 34, 6)
        fs_flag = 2                 '发送了数据的标志     在接收数据的时候判断发的是哪条
    End If
    If zt_flag = 2 Then     '读2个寄存器
        Form4.MSComm1.RThreshold = 9
        Call RD_N_REG(device_id, 49, 2)
        fs_flag = 3                 '发送了数据的标志     在接收数据的时候判断发的是哪条
    End If
    
    
    
    If zt_flag = 100 Then           '顺序写这几个寄存器   工程号可以不写     下面这些也没用到
        Form4.MSComm1.RThreshold = 8
        Call WR_N_REG(device_id, 24, 10)
        
        fs_flag = 1                  '发送了数据的标志     在接收数据的时候判断发的是哪条
        zt_flag = 101
    End If
    If zt_flag = 102 Then
        ReDim dat_temp(5) As Long
        
        temp0 = Val(Text16.Text)        '延时
        temp2 = (temp0 \ 65536)
        dat_temp(1) = temp2                     '高16位
        dat_temp(0) = (temp0 - temp2 * (65536)) '低16位
        
        dat_temp(2) = Val(Text9.Text)  '起始段
        dat_temp(3) = Val(Text10.Text)   '结束段
        dat_temp(4) = Val(Text11.Text)  '段次数
        dat_temp(5) = Val(Text3.Text)  '当前步号
   
        Form4.MSComm1.RThreshold = 8
        Call WR_N_REG(device_id, 34, 6)
        fs_flag = 2
        zt_flag = 103
    End If
    If zt_flag = 104 Then
        ReDim dat_temp(1) As Long
        dat_temp(0) = Val(Text12.Text)  '写启停信号
        dat_temp(1) = Val(Text4.Text)

        Form4.MSComm1.RThreshold = 8
        Call WR_N_REG(device_id, 49, 2)
        fs_flag = 3
        zt_flag = 105
    End If
End Sub
