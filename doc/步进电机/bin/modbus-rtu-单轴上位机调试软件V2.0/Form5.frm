VERSION 5.00
Object = "{648A5603-2C6E-101B-82B6-000000000014}#1.1#0"; "MSCOMM32.OCX"
Begin VB.Form Form5 
   Caption         =   "Form5"
   ClientHeight    =   5655
   ClientLeft      =   6870
   ClientTop       =   2325
   ClientWidth     =   8715
   LinkTopic       =   "Form5"
   ScaleHeight     =   5655
   ScaleWidth      =   8715
   StartUpPosition =   2  '屏幕中心
   Begin VB.TextBox Text12 
      BorderStyle     =   0  'None
      Height          =   375
      Left            =   5640
      TabIndex        =   24
      Text            =   "OFF"
      Top             =   4800
      Width           =   375
   End
   Begin VB.TextBox Text11 
      BorderStyle     =   0  'None
      Height          =   375
      Left            =   4680
      TabIndex        =   23
      Text            =   "OFF"
      Top             =   4800
      Width           =   375
   End
   Begin VB.TextBox Text10 
      BorderStyle     =   0  'None
      Height          =   375
      Left            =   3720
      TabIndex        =   22
      Text            =   "OFF"
      Top             =   4800
      Width           =   375
   End
   Begin VB.TextBox Text9 
      BorderStyle     =   0  'None
      Height          =   375
      Left            =   2760
      TabIndex        =   21
      Text            =   "OFF"
      Top             =   4800
      Width           =   375
   End
   Begin VB.TextBox Text8 
      BorderStyle     =   0  'None
      Height          =   375
      Left            =   1920
      TabIndex        =   20
      Text            =   "OFF"
      Top             =   4800
      Width           =   375
   End
   Begin VB.TextBox Text7 
      BorderStyle     =   0  'None
      Height          =   375
      Left            =   3720
      TabIndex        =   19
      Text            =   "OFF"
      Top             =   4200
      Width           =   375
   End
   Begin VB.TextBox Text6 
      BorderStyle     =   0  'None
      Height          =   375
      Left            =   2760
      TabIndex        =   18
      Text            =   "OFF"
      Top             =   4200
      Width           =   375
   End
   Begin VB.TextBox Text5 
      BorderStyle     =   0  'None
      Height          =   375
      Left            =   1920
      TabIndex        =   17
      Text            =   "OFF"
      Top             =   4200
      Width           =   375
   End
   Begin VB.TextBox Text4 
      BorderStyle     =   0  'None
      Height          =   375
      Left            =   1920
      TabIndex        =   16
      Text            =   "OFF"
      Top             =   3480
      Width           =   375
   End
   Begin VB.CommandButton Command5 
      Caption         =   "坐标清零00011"
      Height          =   615
      Left            =   7320
      TabIndex        =   12
      Top             =   4320
      Width           =   1095
   End
   Begin VB.CommandButton Command4 
      Caption         =   "回数据零00007"
      Height          =   615
      Left            =   7320
      TabIndex        =   11
      Top             =   3480
      Width           =   1095
   End
   Begin VB.CommandButton Command3 
      Caption         =   "工程停止00004"
      Height          =   615
      Left            =   7320
      TabIndex        =   10
      Top             =   2640
      Width           =   1095
   End
   Begin VB.CommandButton Command2 
      Caption         =   "工程启动00009"
      Height          =   615
      Left            =   7320
      TabIndex        =   9
      Top             =   1800
      Width           =   1095
   End
   Begin VB.TextBox Text3 
      Height          =   495
      Left            =   2400
      TabIndex        =   7
      Text            =   "0"
      Top             =   1680
      Width           =   855
   End
   Begin VB.TextBox Text2 
      BorderStyle     =   0  'None
      Height          =   495
      Left            =   2400
      Locked          =   -1  'True
      TabIndex        =   6
      Text            =   "0"
      Top             =   2520
      Width           =   855
   End
   Begin VB.TextBox Text1 
      BorderStyle     =   0  'None
      Height          =   495
      Left            =   2280
      Locked          =   -1  'True
      TabIndex        =   3
      Text            =   "0"
      Top             =   960
      Width           =   1815
   End
   Begin VB.Timer Timer1 
      Interval        =   100
      Left            =   960
      Top             =   240
   End
   Begin MSCommLib.MSComm MSComm1 
      Left            =   240
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
      Left            =   7680
      TabIndex        =   1
      Top             =   120
      Width           =   855
   End
   Begin VB.Label Label9 
      Caption         =   "次"
      Height          =   375
      Left            =   3480
      TabIndex        =   25
      Top             =   1800
      Width           =   255
   End
   Begin VB.Label Label8 
      Caption         =   "1-5路输入状态40043--40047"
      Height          =   375
      Left            =   480
      TabIndex        =   15
      Top             =   4800
      Width           =   1335
   End
   Begin VB.Label Label7 
      Caption         =   "输出状态40048 40056 40057"
      Height          =   615
      Left            =   480
      TabIndex        =   14
      Top             =   4080
      Width           =   1095
   End
   Begin VB.Label Label6 
      Caption         =   "电机状态40049"
      Height          =   375
      Left            =   480
      TabIndex        =   13
      Top             =   3480
      Width           =   855
   End
   Begin VB.Label Label5 
      Caption         =   "步"
      Height          =   375
      Left            =   3360
      TabIndex        =   8
      Top             =   2640
      Width           =   255
   End
   Begin VB.Label Label4 
      Caption         =   "当前工程第40042"
      Height          =   615
      Left            =   1200
      TabIndex        =   5
      Top             =   2520
      Width           =   1215
   End
   Begin VB.Label Label3 
      Caption         =   "当前工程运行次数40021"
      Height          =   375
      Left            =   840
      TabIndex        =   4
      Top             =   1800
      Width           =   1455
   End
   Begin VB.Label Label2 
      Caption         =   "当前坐标40023 40024"
      Height          =   615
      Left            =   1200
      TabIndex        =   2
      Top             =   960
      Width           =   855
   End
   Begin VB.Label Label1 
      Caption         =   "自动运行界面"
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
      Left            =   3480
      TabIndex        =   0
      Top             =   240
      Width           =   2295
   End
End
Attribute VB_Name = "Form5"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim zt_flag As Byte     '读操作变量
Dim fs_flag As Byte

Dim zt_flag2 As Byte    '写和线圈操作变量
Dim sta_flag As Byte


Private Sub Command1_Click()
    Form5.MSComm1.PortOpen = False
    Unload Form5
    
    Form1.Show
End Sub

Private Sub Command2_Click()
    zt_flag2 = 10
        
End Sub

Private Sub Command3_Click()
    zt_flag2 = 11
End Sub

Private Sub Command4_Click()
    zt_flag2 = 12
End Sub

Private Sub Command5_Click()
   zt_flag2 = 13
End Sub

Private Sub Command6_Click()
     zt_flag = 0
End Sub

Private Sub Form_Load()
    Form5.MSComm1.CommPort = serial_num   '输入串口号
    Form5.MSComm1.InputLen = 1024
    Form5.MSComm1.Settings = baud
    Form5.MSComm1.InputMode = 1 '1以二进制方式取，0表示文本方式
    Form5.MSComm1.InputLen = 0 '取输入的全部值
    
    Form5.MSComm1.RThreshold = 1
    
    Form5.MSComm1.PortOpen = True
    
    Timer1.Enabled = True
    zt_flag = 0              '一进入界面就读第1条
    fs_flag = 0
    

    zt_flag2 = 0
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
            
             '//////////////////////////////////////////// 写寄存器反馈
            If zt_flag2 = 20 And (inp(0)) = (device_id) And (inp(1)) = 10 Then    '改工作次数
                zt_flag2 = 0   '21
                
            End If
            If zt_flag2 = 21 And (inp(0)) = (device_id) And (inp(1)) = 5 Then    '保存
                zt_flag2 = 0
                
            End If
            
             '//////////////////////////////////////////// 写线圈反馈
            If zt_flag2 = 10 And (inp(0)) = (device_id) And (inp(1)) = 5 Then    '启动工程
                zt_flag2 = 0
                zt_flag = 0 '可以读
                fs_flag = 0
            End If
             If zt_flag2 = 11 And (inp(0)) = (device_id) And (inp(1)) = 5 Then    '停止工程
                zt_flag2 = 0
                zt_flag = 0 '可以读
                fs_flag = 0
            End If
             If zt_flag2 = 12 And (inp(0)) = (device_id) And (inp(1)) = 5 Then    '回零
                zt_flag2 = 0
                zt_flag = 0 '可以读
                fs_flag = 0
            End If
             If zt_flag2 = 13 And (inp(0)) = (device_id) And (inp(1)) = 5 Then    '坐标清零
                zt_flag2 = 0
                zt_flag = 0 '可以读
                fs_flag = 0
            End If
            
            '//////////////////////////////////////////// 读反馈
            If zt_flag = 0 And fs_flag = 1 And (inp(0)) = (device_id) And (inp(1)) = 3 Then
              
                 Text3.Text = Val((inp(3) * (256#) + inp(4) + inp(5) * (16777216#) + inp(6) * CDbl(65536)))    '工作次数
               
                
                Text1.Text = Val((inp(9) * (256#) + inp(10) + inp(11) * (16777216#) + inp(12) * CDbl(65536)))   '可取2位小数
                'Text1.Text = Val((inp(7) * (256#) + inp(8) + inp(9) * (16777216#) + inp(10) * CDbl(65536)))   '可取2位小数
                
                If Val(Text1.Text) > &H7FFFFFFF Then
                    Text1.Text = "-" & (4294967296# - Val(Text1.Text)) / 100
                Else
                    Text1.Text = Text1.Text / 100
    
                End If
             
                zt_flag = 1
            End If
            If zt_flag = 1 And fs_flag = 2 And (inp(0)) = (device_id) And (inp(1)) = 3 Then
                Text2.Text = (inp(3) * (256) + inp(4))  '当前步号
                If (inp(5) * (256) + inp(6)) = 1 Then
                    Text8.Text = "ON"
                Else
                    Text8.Text = "OFF"
                End If
                If (inp(7) * (256) + inp(8)) = 1 Then
                    Text9.Text = "ON"
                Else
                    Text9.Text = "OFF"
                End If
                If (inp(9) * (256) + inp(10)) = 1 Then
                    Text10.Text = "ON"
                Else
                    Text10.Text = "OFF"
                End If
                If (inp(11) * (256) + inp(12)) = 1 Then
                    Text11.Text = "ON"
                Else
                    Text11.Text = "OFF"
                End If
                If (inp(13) * (256) + inp(14)) = 1 Then
                    Text12.Text = "ON"
                Else
                    Text12.Text = "OFF"
                End If
                
                If (inp(15) * (256) + inp(16)) = 1 Then '输出1
                    Text5.Text = "ON"
                Else
                    Text5.Text = "OFF"
                End If
                If (inp(17) * (256) + inp(18)) = 1 Then '电机状态
                    Text4.Text = "ON"
                Else
                    Text4.Text = "OFF"
                End If
              
                 zt_flag = 2
            End If
            If zt_flag = 2 And fs_flag = 3 And (inp(0)) = (device_id) And (inp(1)) = 3 Then
                If (inp(3) * (256) + inp(4)) = 1 Then
                    Text6.Text = "ON"
                Else
                    Text6.Text = "OFF"
                End If
                If (inp(5) * (256) + inp(6)) = 1 Then
                    Text7.Text = "ON"
                Else
                    Text7.Text = "OFF"
                End If
           
                zt_flag = 0   '读完毕
            End If
            
            
    End Select

End Sub

Private Sub Text3_Change()     '写这个的时候不能再读了
    If zt_flag2 = 19 Then
        zt_flag2 = 20
        
    End If
End Sub

Private Sub Text3_Click()
    zt_flag2 = 19
End Sub

Private Sub Timer1_Timer()
    Dim strbuf As String
     Dim temp0 As Double
    Dim temp2 As Integer

    If zt_flag2 = 10 Then       '工程启动
        If zt_flag = 0 Then    '读完了才能发
            zt_flag = 200 '不能读
            fs_flag = 0
            'zt_flag2 = 66
            Form5.MSComm1.RThreshold = 8
            Call Coil_ON(device_id, 8)
        End If
    End If
    If zt_flag2 = 11 Then
        If zt_flag = 0 Then    '读完了才能发
            zt_flag = 200
            'zt_flag2 = 67
            Form5.MSComm1.RThreshold = 8
            Call Coil_ON(device_id, 3)
        End If
    End If
    If zt_flag2 = 12 Then
        If zt_flag = 0 Then    '读完了才能发
            zt_flag = 200
            'zt_flag2 = 68
            Form5.MSComm1.RThreshold = 8
            Call Coil_ON(device_id, 6)
        End If
    End If
    If zt_flag2 = 13 Then
        If zt_flag = 0 Then    '读完了才能发
            zt_flag = 200
            'zt_flag2 = 69
            Form5.MSComm1.RThreshold = 8
            Call Coil_ON(device_id, 10)
        End If
    End If
    
    
    
    '''一直读， 除了写操作的时候
    If zt_flag2 <> 20 And zt_flag = 0 Then  '读20 21  23  24
        
        Form5.MSComm1.RThreshold = 15
        Call RD_N_REG(device_id, 19, 5)
        fs_flag = 1
    End If
    If zt_flag2 <> 20 And zt_flag = 1 Then  '读42 ---49
        Form5.MSComm1.RThreshold = 21
        Call RD_N_REG(device_id, 41, 8)
        fs_flag = 2
    End If
    If zt_flag2 <> 20 And zt_flag = 2 Then  '读56 57
        Form5.MSComm1.RThreshold = 9
        Call RD_N_REG(device_id, 55, 2)
        fs_flag = 3
    End If
    
    
    ''''///////写操作
    If zt_flag2 = 20 Then
        fs_flag = 0
        zt_flag = 0
        
        'Call WR_1_REG(device_id, 19, Val(Text3.Text))
        
         ReDim dat_temp(1) As Long
        temp0 = Val(Text3.Text)
        temp2 = (temp0 \ 65536)

        dat_temp(1) = temp2                     '高16位
        dat_temp(0) = (temp0 - temp2 * (65536)) '低16位
        Form5.MSComm1.RThreshold = 8
        Call WR_N_REG(device_id, 19, 2)
    End If
'     If zt_flag2 = 21 Then     '这段可以不要    这个参数不能修改
'        Call WR_1_REG(1, 41, Val(Text2.Text))
'    End If
    If zt_flag2 = 21 Then
        Form5.MSComm1.RThreshold = 8
       Call Coil_ON(device_id, 0)
    End If
    
    
    

    

End Sub
