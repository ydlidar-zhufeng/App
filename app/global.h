#ifndef GLOBAL_H
#define GLOBAL_H
#include <iostream>
#define  BtnMaxTimeout  1000

#define  DTR_CMD_DEVICE_NUM      0x01

#define  WRITE_MULTIPLE_REGISTER_FUNC_CODE  0x10
#define  WRITE_SINGLE_REGISTER_FUNC_CODE  0x06
#define  WRITE_SINGLE_COIL_FUNC_CODE     0x05
#define  READ_SINGLE_COIL_FUNC_CODE      0x01
#define  READ_REGISTER_FUNC_CODE         0x03

//寄存器命令(后缀为two代表值占两个寄存器)
#define  ADDR_DIS_START_ADDRESS_TWO     0x0900 //距离
#define  ADDR_RUN_DIRECTION_ONE       0x0b00  //方向
#define  ADDR_SPEECH_START_ADDRESS_ONE   0x0800  //速度
#define  ADDR_GET_CUR_POS_TWO         0x1600 //获取当前点坐标

#define  ADDR_STEP_ANGLE_ONE       0x0000   //步距角
#define  ADDR_PITCH_TWO            0x0400  //螺距
#define  ADDR_POSTV_LSIG_ONE           0x0e00  //正限位信号
#define  ADDR_NEGTV_LSIG_ONE      0x0f00  //负限位信号
#define  ADDR_RUNWAY_ONE         0x4b00 //运行方式，相对运行、绝对运行，只针对单次运行
#define  ADDR_FORWARE_ROTATION_START_SIGNAL_ONE   0x4d00 //正转启动信号
#define  ADDR_REVEARSE_ROTATION_START_SIGNAL_ONE   0x4e00 //反转启动信号

//线圈命令
#define  ADDR_POS_SET_ZERO      0x0a00
#define  ADDR_DTR_STOP         0x0300
#define  ADDR_FORWARD_ROTATION   0x0400
#define  ADDR_REVEARSE_ROTATION  0x0500
#define  ADDR_RETURN_ZERO_POS    0x0600
#define  ADDR_DTR_ONCE_RUN            0x0700 //单次运行

//线圈赋值
#define  DATA_COIL_TURN_ON        0x00ff
#define  DATA_COIL_TURN_OFF       0x0000



extern  uint16_t  htou16(uint16_t data);

#pragma pack(push,1)

//写单个线圈、寄存器
struct write_single_address {
    uint8_t   device_number = DTR_CMD_DEVICE_NUM;
    uint8_t   func_code;
    uint16_t  start_div;
    uint16_t  data;
    uint16_t  crc;
};

//读寄存器
struct read_register {
    uint8_t   device_number = DTR_CMD_DEVICE_NUM;
    uint8_t   func_code;
    uint16_t   start_div;
    uint16_t  data_num;
    uint16_t  crc;
};

//读两个寄存器的回包
struct read_two_register_rtn {
    uint8_t   device_number = DTR_CMD_DEVICE_NUM;
    uint8_t   func_code;
    uint8_t   data_num = 4;
    uint16_t  first_data;
    uint16_t  second_data;
    uint16_t  crc;
};

//读单个寄存器的回包
struct read_one_register_rtn {
    uint8_t   device_number = DTR_CMD_DEVICE_NUM;
    uint8_t   func_code;
    uint8_t   data_num = 2;
    uint16_t  data;
    uint16_t  crc;
};

//读四个寄存器的回包
struct read_four_register_rtn {
    uint8_t   device_number = DTR_CMD_DEVICE_NUM;
    uint8_t   func_code;
    uint8_t   data_num;
    uint16_t  data[4];
    uint16_t  crc;
};

//一次性写4个寄存器，刚好写下速度,距离,方向
struct write_four_address {
    uint8_t   device_number = DTR_CMD_DEVICE_NUM;
    uint8_t   func_code;
    uint16_t  start_div;
    uint16_t  register_num = htou16(4);
    uint8_t   data_size = 8;
    uint16_t  data[4];
    uint16_t   crc;
};

//一次写两个寄存器
struct write_two_address {
    uint8_t   device_number = DTR_CMD_DEVICE_NUM;
    uint8_t   func_code;
    uint16_t  start_div;
    uint16_t  register_num = htou16(0x0002);
    uint8_t   data_size = 4;
    uint16_t  data[2];
    uint16_t   crc;
};






//写寄存器的回包
struct  write_address_return_cmd {
    uint8_t   device_number;
    uint8_t   func_code;
    uint16_t  start_div;
    uint16_t  register_num;
    uint16_t  crc;
    write_address_return_cmd& operator = (const write_address_return_cmd &data){
        this->device_number = data.device_number;
        this->func_code = data.func_code;
        this->start_div = data.device_number;
        this->register_num = data.register_num;
        this->crc = data.crc;
        return *this;
    }
    bool  operator == (const write_single_address &data){
        bool flag = false;
        if(this->device_number == data.device_number && this->func_code == data.func_code && this->start_div == data.device_number
                && this->register_num == data.data && this->crc == data.crc)
            flag = true;
        return  flag;
    }
    bool  operator != (const write_single_address &data){
        bool flag = false;
        if(this->device_number != data.device_number || this->func_code != data.func_code || this->start_div != data.start_div
                || this->register_num != data.data || this->crc != data.crc)
            flag = true;
        return  flag;
    }
};

#pragma pack(pop)



#endif // GLOBAL_H
