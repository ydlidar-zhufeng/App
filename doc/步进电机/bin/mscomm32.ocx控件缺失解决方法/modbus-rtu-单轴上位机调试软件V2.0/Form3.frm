VERSION 5.00
Object = "{648A5603-2C6E-101B-82B6-000000000014}#1.1#0"; "MSCOMM32.OCX"
Begin VB.Form Form3 
   Caption         =   "Form3"
   ClientHeight    =   5835
   ClientLeft      =   6870
   ClientTop       =   3030
   ClientWidth     =   8385
   LinkTopic       =   "Form3"
   ScaleHeight     =   5835
   ScaleWidth      =   8385
   StartUpPosition =   2  '屏幕中心
   Begin VB.TextBox Text5 
      Height          =   375
      Left            =   6720
      TabIndex        =   26
      Text            =   "0"
      Top             =   5160
      Width           =   735
   End
   Begin VB.CommandButton Command14 
      Caption         =   "回机械零  00010"
      Height          =   615
      Left            =   3360
      TabIndex        =   25
      Top             =   5040
      Width           =   1455
   End
   Begin VB.CommandButton Command13 
      Caption         =   "参数保存 00001"
      Height          =   615
      Left            =   5880
      Style           =   1  'Graphical
      TabIndex        =   24
      Top             =   1920
      Width           =   1335
   End
   Begin VB.TextBox Text10 
      Height          =   375
      Left            =   480
      TabIndex        =   23
      Top             =   4560
      Width           =   7215
   End
   Begin VB.Timer Timer1 
      Interval        =   100
      Left            =   5160
      Top             =   120
   End
   Begin MSCommLib.MSComm MSComm1 
      Left            =   5880
      Top             =   0
      _ExtentX        =   1005
      _ExtentY        =   1005
      _Version        =   393216
      DTREnable       =   -1  'True
   End
   Begin VB.CommandButton Command12 
      BackColor       =   &H00FF8080&
      Caption         =   "参数下载"
      Height          =   615
      Left            =   5880
      Style           =   1  'Graphical
      TabIndex        =   21
      Top             =   1080
      Width           =   1335
   End
   Begin VB.TextBox Text4 
      Height          =   495
      Left            =   3840
      TabIndex        =   20
      Text            =   "0"
      Top             =   1920
      Width           =   1095
   End
   Begin VB.TextBox Text3 
      Height          =   495
      Left            =   3840
      TabIndex        =   19
      Text            =   "0"
      Top             =   1200
      Width           =   1095
   End
   Begin VB.CommandButton Command11 
      Caption         =   "输出3关00017"
      Height          =   495
      Left            =   6120
      TabIndex        =   16
      Top             =   3600
      Width           =   1095
   End
   Begin VB.CommandButton Command10 
      Caption         =   "输出3开00016"
      Height          =   495
      Left            =   6120
      TabIndex        =   15
      Top             =   2880
      Width           =   1095
   End
   Begin VB.CommandButton Command9 
      Caption         =   "输出2关00015"
      Height          =   495
      Left            =   4800
      TabIndex        =   14
      Top             =   3600
      Width           =   1095
   End
   Begin VB.CommandButton Command8 
      Caption         =   "输出2开00014"
      Height          =   495
      Left            =   4800
      TabIndex        =   13
      Top             =   2880
      Width           =   1095
   End
   Begin VB.CommandButton Command7 
      Caption         =   "输出1关00013"
      Height          =   495
      Left            =   3480
      TabIndex        =   12
      Top             =   3600
      Width           =   1095
   End
   Begin VB.CommandButton Command6 
      Caption         =   "输出1开00012"
      Height          =   495
      Left            =   3480
      TabIndex        =   11
      Top             =   2880
      Width           =   1095
   End
   Begin VB.ComboBox Combo1 
      Height          =   300
      ItemData        =   "Form3.frx":0000
      Left            =   840
      List            =   "Form3.frx":000A
      TabIndex        =   10
      Text            =   "Combo1"
      Top             =   600
      Width           =   1095
   End
   Begin VB.CommandButton Command5 
      Caption         =   "停止  00004"
      Height          =   495
      Left            =   840
      TabIndex        =   9
      Top             =   3600
      Width           =   1095
   End
   Begin VB.CommandButton Command4 
      Caption         =   "反转  00006"
      Height          =   495
      Left            =   2160
      TabIndex        =   8
      Top             =   3600
      Width           =   1095
   End
   Begin VB.CommandButton Command3 
      Caption         =   "正转  00005"
      Height          =   495
      Left            =   2160
      TabIndex        =   7
      Top             =   2880
      Width           =   1095
   End
   Begin VB.CommandButton Command2 
      Caption         =   "单次运行00008"
      Height          =   495
      Left            =   840
      TabIndex        =   6
      Top             =   2880
      Width           =   1095
   End
   Begin VB.TextBox Text2 
      Height          =   495
      Left            =   840
      TabIndex        =   5
      Text            =   "0"
      Top             =   1920
      Width           =   1095
   End
   Begin VB.TextBox Text1 
      Height          =   495
      Left            =   840
      TabIndex        =   4
      Text            =   "0"
      Top             =   1200
      Width           =   1095
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
      Left            =   7440
      TabIndex        =   0
      Top             =   120
      Width           =   735
   End
   Begin VB.Label Label23 
      BackColor       =   &H00FF8080&
      Caption         =   "接收数据显示"
      Height          =   255
      Left            =   480
      TabIndex        =   30
      Top             =   5040
      Width           =   1215
   End
   Begin VB.Label Label22 
      BackColor       =   &H00FF8080&
      Caption         =   "修改参数后，点击参数下载"
      Height          =   255
      Left            =   5520
      TabIndex        =   29
      Top             =   720
      Width           =   2295
   End
   Begin VB.Label Label8 
      Caption         =   "RPM"
      Height          =   255
      Left            =   2040
      TabIndex        =   28
      Top             =   1320
      Width           =   375
   End
   Begin VB.Label Label7 
      Caption         =   "运行到位显示40013"
      Height          =   375
      Left            =   5520
      TabIndex        =   27
      Top             =   5160
      Width           =   1095
   End
   Begin VB.Label Label6 
      Caption         =   "方向40012"
      Height          =   375
      Left            =   240
      TabIndex        =   22
      Top             =   600
      Width           =   495
   End
   Begin VB.Label Label5 
      Caption         =   "工程停止信号40019"
      Height          =   375
      Left            =   2640
      TabIndex        =   18
      Top             =   2040
      Width           =   1095
   End
   Begin VB.Label Label4 
      Caption         =   "工程启动信号40018"
      Height          =   375
      Left            =   2640
      TabIndex        =   17
      Top             =   1200
      Width           =   1095
   End
   Begin VB.Label Label3 
      Caption         =   "距离40010 40011"
      Height          =   615
      Left            =   240
      TabIndex        =   3
      Top             =   1920
      Width           =   495
   End
   Begin VB.Label Label2 
      Caption         =   "速度40009"
      Height          =   375
      Left            =   240
      TabIndex        =   2
      Top             =   1320
      Width           =   495
   End
   Begin VB.Label Label1 
      Caption         =   "手动调试界面"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   14.25
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   2640
      TabIndex        =   1
      Top             =   120
      Width           =   1935
   End
End
Attribute VB_Name = "Form3"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim zt_flag As Byte
Dim fs_flag As Byte

Private Sub Command1_Click()
    Form3.MSComm1.PortOpen = False
    Unload Form3
    
    Form1.Show
End Sub

Private Sub Command10_Click()
    Form3.MSComm1.RThreshold = 8
    Call Coil_ON(device_id, 15)
End Sub

Private Sub Command11_Click()
    Form3.MSComm1.RThreshold = 8
    Call Coil_ON(device_id, 16)
End Sub

Private Sub Command12_Click()
    Dim temp0 As Double
    Dim temp1 As Double
    
    Dim temp2 As Integer

    ReDim dat_temp(3) As Long
    
    dat_temp(0) = Val(Text1.Text)
    
    temp0 = Val(Text2.Text) * 100   '螺距
    temp2 = (temp0 \ 65536)         '高16位
    dat_temp(2) = temp2                  '高16位
    dat_temp(1) = (temp0 - temp2 * (65536))   '低16位
    
    If Combo1.Text = Combo1.List(0) Then
        dat_temp(3) = 0
    ElseIf Combo1.Text = Combo1.List(1) Then
        dat_temp(3) = 1
    End If

    zt_flag = 100
    Command12.BackColor = vbRed
End Sub

Private Sub Command13_Click()
    zt_flag = 5
    Command13.BackColor = vbRed
End Sub

Private Sub Command14_Click()
    Form3.MSComm1.RThreshold = 8
   Call Coil_ON(device_id, 9)
End Sub

Private Sub Command2_Click()
    Form3.MSComm1.RThreshold = 8
   Call Coil_ON(device_id, 7)
    zt_flag = 150
    fs_flag = 150
End Sub

Private Sub Command3_Click()
    Form3.MSComm1.RThreshold = 8
    Call Coil_ON(device_id, 4)
    Text5.Text = 0
End Sub

Private Sub Command4_Click()
    Form3.MSComm1.RThreshold = 8
    Call Coil_ON(device_id, 5)
    Text5.Text = 0
End Sub

Private Sub Command5_Click()
    Form3.MSComm1.RThreshold = 8
    Call Coil_ON(device_id, 3)
    Text5.Text = 0
     zt_flag = 155
End Sub

Private Sub Command6_Click()
    Form3.MSComm1.RThreshold = 8
    Call Coil_ON(device_id, 11)
End Sub

Private Sub Command7_Click()
    Form3.MSComm1.RThreshold = 8
    Call Coil_ON(device_id, 12)
End Sub

Private Sub Command8_Click()
    Form3.MSComm1.RThreshold = 8
    Call Coil_ON(device_id, 13)
End Sub

Private Sub Command9_Click()
    Form3.MSComm1.RThreshold = 8
    Call Coil_ON(device_id, 14)
End Sub

Private Sub Form_Load()
    Form3.MSComm1.CommPort = serial_num   '输入串口号
    Form3.MSComm1.InputLen = 1024
    Form3.MSComm1.Settings = baud
    Form3.MSComm1.InputMode = 1 '1以二进制方式取，0表示文本方式
    Form3.MSComm1.InputLen = 0 '取输入的全部值
    
    Form3.MSComm1.RThreshold = 1
    
    Form3.MSComm1.PortOpen = True
    
    Timer1.Enabled = True
    zt_flag = 0              '一进入界面就读第1条
    fs_flag = 0
    
    Combo1.Text = Combo1.List(0)

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
            
            '//////////////////////////////////////////// 读反馈
            If zt_flag = 0 And fs_flag = 1 And (inp(0)) = (device_id) And (inp(1)) = 3 Then
                
                Text1.Text = cal_2_bs(inp(3), inp(4))  '(inp(3) * (256) + inp(4))
                Text2.Text = (inp(5) * (256#) + inp(6) + inp(7) * (16777216#) + inp(8) * CDbl(65536)) / 100   '可取2位小数
                If cal_2_bs(inp(9), inp(10)) = 0 Then
                    Combo1.Text = Combo1.List(0)
                ElseIf cal_2_bs(inp(9), inp(10)) = 1 Then
                    Combo1.Text = Combo1.List(1)
                End If
                
                zt_flag = 1   '准备读下一条
            End If
            If zt_flag = 1 And fs_flag = 2 And (inp(0)) = (device_id) And (inp(1)) = 3 Then
                
                Text3.Text = cal_2_bs(inp(3), inp(4))  '(inp(3) * (256) + inp(4))
                Text4.Text = cal_2_bs(inp(5), inp(6))  '(inp(5) * (256) + inp(6))
                zt_flag = 2   '准备读下一条
            End If
            
            If zt_flag = 150 And fs_flag = 10 And (inp(0)) = (device_id) And (inp(1)) = 3 Then
                
                Text5.Text = (inp(3) * (256) + inp(4))
                
                If (inp(3) * (256) + inp(4)) = 1 Then
                     zt_flag = 151
                ElseIf (inp(3) * (256) + inp(4)) = 0 Then
                    zt_flag = 150   '
                End If
                fs_flag = 150
            End If
            
            
            
            '////////////////////////////////////////////  写反馈
            If zt_flag = 100 And fs_flag = 1 And (inp(0)) = (device_id) And (inp(1)) = &H10 Then
                zt_flag = 101
            End If
            If zt_flag = 101 And fs_flag = 2 And (inp(0)) = (device_id) And (inp(1)) = &H10 Then
                zt_flag = 102                       '写数据完毕
                Command12.BackColor = &HFF8080
            End If


            If zt_flag = 5 And (inp(0)) = (device_id) And (inp(1)) = 5 Then
                zt_flag = 6
                Command13.BackColor = &H8000000F
            End If
  
            
            num1 = UBound(inp)
            For i = 0 To num1
                Text10.Text = Text10.Text & Hex(inp(i))      '将接收到的数据显示在文本框
                Text10.Text = Text10.Text & " "
            Next
        
    End Select
End Sub

Private Sub Text10_Click()
    Text10.Text = ""
End Sub

Private Sub Timer1_Timer()
    If zt_flag = 0 Then     '读4个寄存器
        Form3.MSComm1.RThreshold = 13
        Call RD_N_REG(device_id, 8, 4)
        fs_flag = 1                 '发送了数据的标志     在接收数据的时候判断发的是哪条
    End If
    If zt_flag = 1 Then     '读4个寄存器
        Form3.MSComm1.RThreshold = 9
        Call RD_N_REG(device_id, 17, 2)
        fs_flag = 2                 '发送了数据的标志     在接收数据的时候判断发的是哪条
    End If
    
    
    If zt_flag = 100 Then           '顺序写这几个寄存器
        Form3.MSComm1.RThreshold = 8
        Call WR_N_REG(device_id, 8, 4)
        fs_flag = 1                  '发送了数据的标志     在接收数据的时候判断发的是哪条
    End If
    If zt_flag = 101 Then
        ReDim dat_temp(1) As Long
        dat_temp(0) = Val(Text3.Text)  '写启停信号
        dat_temp(1) = Val(Text4.Text)
        
        Form3.MSComm1.RThreshold = 8
        Call WR_N_REG(device_id, 17, 2)
        fs_flag = 2
    End If
    
     If zt_flag = 5 Then
        Form3.MSComm1.RThreshold = 8
        Call Coil_ON(device_id, 0)
    End If
    
       If zt_flag = 150 And fs_flag = 150 Then      '读是否到位
        Form3.MSComm1.RThreshold = 7
        Call RD_N_REG(device_id, 12, 1)
        fs_flag = 10            '
    End If


End Sub
