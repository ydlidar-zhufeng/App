VERSION 5.00
Object = "{648A5603-2C6E-101B-82B6-000000000014}#1.1#0"; "MSCOMM32.OCX"
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   5325
   ClientLeft      =   6180
   ClientTop       =   2565
   ClientWidth     =   9210
   LinkTopic       =   "Form1"
   ScaleHeight     =   5325
   ScaleWidth      =   9210
   StartUpPosition =   2  '屏幕中心
   Begin VB.CommandButton Command9 
      Caption         =   "参数初始化00037"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   5280
      Style           =   1  'Graphical
      TabIndex        =   20
      Top             =   2640
      Width           =   1455
   End
   Begin VB.CommandButton Command8 
      Caption         =   "参数清零00003"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   2760
      Style           =   1  'Graphical
      TabIndex        =   14
      Top             =   2640
      Width           =   1455
   End
   Begin VB.CommandButton Command7 
      Caption         =   "设定新ID"
      Enabled         =   0   'False
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   5040
      Style           =   1  'Graphical
      TabIndex        =   13
      Top             =   720
      Width           =   1215
   End
   Begin VB.TextBox Text2 
      Alignment       =   2  'Center
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
      Left            =   4200
      TabIndex        =   12
      Text            =   "1"
      Top             =   720
      Width           =   735
   End
   Begin VB.TextBox Text1 
      Alignment       =   2  'Center
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   390
      Left            =   1320
      TabIndex        =   10
      Text            =   "9600"
      Top             =   120
      Width           =   1095
   End
   Begin VB.CommandButton Command6 
      Caption         =   "退出"
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
      Left            =   8040
      TabIndex        =   8
      Top             =   120
      Width           =   975
   End
   Begin VB.CommandButton Command5 
      Caption         =   "自动运行界面"
      Height          =   735
      Left            =   5280
      TabIndex        =   7
      Top             =   3360
      Width           =   1575
   End
   Begin VB.CommandButton Command3 
      Caption         =   "工程参数界面"
      Height          =   735
      Left            =   2760
      TabIndex        =   6
      Top             =   3360
      Width           =   1575
   End
   Begin VB.CommandButton Command2 
      Caption         =   "手动调试界面"
      Height          =   735
      Left            =   5280
      TabIndex        =   5
      Top             =   1680
      Width           =   1575
   End
   Begin VB.CommandButton Command1 
      Caption         =   "基本参数界面"
      Height          =   735
      Left            =   2760
      TabIndex        =   4
      Top             =   1680
      Width           =   1575
   End
   Begin VB.CommandButton Command4 
      Caption         =   "设定"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   1680
      Style           =   1  'Graphical
      TabIndex        =   3
      Top             =   720
      Width           =   855
   End
   Begin VB.TextBox Text5 
      Alignment       =   2  'Center
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
      Left            =   840
      TabIndex        =   1
      Text            =   "4"
      Top             =   720
      Width           =   735
   End
   Begin VB.Timer Timer1 
      Interval        =   100
      Left            =   240
      Top             =   3840
   End
   Begin MSCommLib.MSComm MSComm1 
      Left            =   840
      Top             =   3720
      _ExtentX        =   1005
      _ExtentY        =   1005
      _Version        =   393216
      DTREnable       =   -1  'True
      BaudRate        =   115200
   End
   Begin VB.Label Label8 
      BackColor       =   &H00FF80FF&
      Caption         =   "控制器需要断电重启才生效"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   6120
      TabIndex        =   19
      Top             =   1320
      Width           =   3135
   End
   Begin VB.Label Label7 
      BackColor       =   &H00FF80FF&
      Caption         =   "注意：点击设定新ID之后，"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   6360
      TabIndex        =   18
      Top             =   960
      Width           =   2895
   End
   Begin VB.Label Label6 
      Caption         =   "若串口号下方提示：连接成功，则表示通信正常。无提示表示通信不正常。"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   255
      Left            =   960
      TabIndex        =   17
      Top             =   4800
      Width           =   8055
   End
   Begin VB.Label Label5 
      Caption         =   "软件操作步骤：1、输入波特率，串口号，设备ID号，2、然后点击设定按钮即可。"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   255
      Left            =   480
      TabIndex        =   16
      Top             =   4320
      Width           =   8655
   End
   Begin VB.Label Label4 
      Height          =   375
      Left            =   480
      TabIndex        =   15
      Top             =   1320
      Width           =   1095
   End
   Begin VB.Label Label3 
      Caption         =   "设备ID号40017"
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
      Left            =   3120
      TabIndex        =   11
      Top             =   720
      Width           =   1095
   End
   Begin VB.Label Label2 
      Caption         =   "通信波特率"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   0
      TabIndex        =   9
      Top             =   120
      Width           =   1455
   End
   Begin VB.Label Label9 
      Caption         =   "串口号"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   0
      TabIndex        =   2
      Top             =   840
      Width           =   975
   End
   Begin VB.Label Label1 
      Caption         =   "Modbus-RTU-单轴上位机调试软件"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15.75
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   2760
      TabIndex        =   0
      Top             =   120
      Width           =   5055
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'Private Declare Sub Sleep Lib "kernel32" (ByVal dwMilliseconds As Long)

Dim zt_flag As Byte
Dim fs_flag As Byte
Dim connect_sta As Byte
Dim inp_temp() As Byte


Private Sub Combo1_Change()

End Sub

Private Sub Command1_Click()
    Form1.MSComm1.PortOpen = False
    Unload Form1
    
    Form2.Show
    interface_flag = 2
    
End Sub

Private Sub Command2_Click()
    Form1.MSComm1.PortOpen = False
    Unload Form1
    
    Form3.Show
    interface_flag = 3
End Sub

Private Sub Command3_Click()
    Form1.MSComm1.PortOpen = False
    Unload Form1
    
    Form4.Show
    interface_flag = 4
End Sub

Private Sub Command4_Click()
    
    Dim a(3) As String, s As String
    
    Form1.MSComm1.CommPort = Val(Text5.Text)   '输入串口号
    serial_num = Val(Text5.Text)
    
    
    a(0) = Text1.Text
    a(1) = "N"
    a(2) = "8"
    a(3) = "1"
    baud = Join(a, ",")
    
    usart_baud = Text1.Text
    
    Form1.MSComm1.InputLen = 1024
    Form1.MSComm1.Settings = baud  '"9600,N,8,1"
    Form1.MSComm1.InputMode = 1 '1以二进制方式取，0表示文本方式
    Form1.MSComm1.InputLen = 0 '取输入的全部值
    
    Form1.MSComm1.RThreshold = 1
    
    Form1.MSComm1.PortOpen = True
    Timer1.Enabled = True
    
    device_id = Val(Text2.Text)   '设备号赋初值
  
    Command4.BackColor = vbRed
    interface_flag = 1
    zt_flag = 0
End Sub

Private Sub Command5_Click()
    Form1.MSComm1.PortOpen = False
    Unload Form1
    
    Form5.Show
    interface_flag = 5
End Sub

Private Sub Command6_Click()
    End
End Sub

Private Sub Command7_Click()
    'device_id = Text2.Text
    zt_flag = 5
    Command7.BackColor = vbRed
End Sub

Private Sub Command8_Click()
    Form1.MSComm1.RThreshold = 8
   Call Coil_ON(device_id, 2)
   Command8.BackColor = vbRed
   zt_flag = 10
End Sub

Private Sub Command9_Click()
   Form1.MSComm1.RThreshold = 8
   Call Coil_ON(device_id, 36)
   Command9.BackColor = vbRed
   zt_flag = 20
End Sub

Private Sub Form_Load()
    Form1.MSComm1.InputLen = 1024
    Form1.MSComm1.Settings = baud
    Form1.MSComm1.InputMode = 1 '1以二进制方式取，0表示文本方式
    Form1.MSComm1.InputLen = 0 '取输入的全部值
    
    Form1.MSComm1.RThreshold = 1
    Timer1.Enabled = False
    
    If interface_flag > 1 Then
        Text1.Text = usart_baud
       
        Form1.MSComm1.CommPort = serial_num
        Form1.MSComm1.Settings = baud
        Form1.MSComm1.PortOpen = True
        Timer1.Enabled = True
        
        Command4.BackColor = vbRed
        interface_flag = 1   '恢复本界面功能
        zt_flag = 0
        Text2.Text = device_id
        Timer1.Interval = 100
        
        Text5.Text = serial_num
    End If
    
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
            
         
            
            If inp(0) = &HFF Then
            
            Else
               ' Text3.Text = device_id
                'Text4.Text = inp(1)
            ' 有时候第1个字节会变成0xff  造成溢出 Hex(device_id)
            If zt_flag = 0 And fs_flag = 1 And (inp(0)) = (device_id) And (inp(1)) = &H3 Then
                
                device_id = cal_2_bs(inp(3), inp(4))  'inp(3) * (256) + inp(4)
                If device_id = 0 Or device_id >= 255 Then   '232调试用
                    device_id = 1
                End If
                
                Text2.Text = device_id
              
                
                zt_flag = 1   '读完毕
                
                If connect_sta = 1 Then
                    Label4.Visible = True
                    Label4.Caption = "连接成功！"
                    connect_sta = 2
                    Command7.Enabled = True
                End If
            End If
            
            If zt_flag = 5 And fs_flag = 2 And (inp(0)) = (device_id) And (inp(1)) = &H6 Then
                Command7.BackColor = &H8000000F
                zt_flag = 6   '写完毕
            End If
            If zt_flag = 6 And fs_flag = 3 And (inp(0)) = (device_id) And (inp(1)) = &H5 Then
                zt_flag = 7  '保存完毕
                device_id = Text2.Text
            End If
            
            If zt_flag = 10 And (inp(0)) = (device_id) And (inp(1)) = &H5 Then
                zt_flag = 0  '清零完毕
                Command8.BackColor = &H8000000F
            End If
            
            If zt_flag = 20 And (inp(0)) = (device_id) And (inp(1)) = &H5 Then
                zt_flag = 0  '清零完毕
                Command9.BackColor = &H8000000F
            End If
            
            End If
        
    End Select
End Sub

Private Sub Text6_Click()
    Text6.Text = ""    '清空接收显示
End Sub


Private Sub Timer1_Timer()
    If zt_flag = 0 Then     '读设备号
        Form1.MSComm1.RThreshold = 7
        
         Call RD_N_REG(device_id, 16, 1)                    '读n个字节，要反馈5+2*n 字节
         connect_sta = 1
         fs_flag = 1
    End If
    If zt_flag = 5 Then     '写设备号
        Form1.MSComm1.RThreshold = 8
        'device_id = Text2.Text
        Call WR_1_REG(device_id, 16, Val(Text2.Text))       '写N个字节，要反馈8个字节
        fs_flag = 2
    End If
    If zt_flag = 6 Then     '写完之后  发保存命令
        Form1.MSComm1.RThreshold = 8
        Call Coil_ON(device_id, 0)
        fs_flag = 3
        Timer1.Interval = 300
          
    End If
    
    

End Sub
