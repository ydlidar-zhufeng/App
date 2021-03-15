#ifndef CONFIG_H
#define CONFIG_H

#define TemperatureValueSize 30
#define TemperatureDiff    100
#define GetTempTimes      3
#define  DefaultTimeout   1000
#define PackageDataHeaderLen  10
#define  MaxTempPointSize    2000
#define  EveryPackagePointSize   40
#define   MaxStandardDevitation   20.00
#define   DefaultVectorSize     1000
#include <QDateTime>
//#include <core/base/v8stdint.h>
//#include <vector>
//#include <functional>
#pragma pack(1)

struct _Tof_point{
    int  tof_max;
    int  tof_min;
    double  tof_avg;
    int  peak_max;
    int  peak_min;
    double  peak_avg;
    double  tof_deviation;

    // = 运算符重载
    _Tof_point& operator = (const _Tof_point &point){
        this->tof_max = point.tof_max;
        this->tof_avg = point.tof_avg;
        this->tof_min = point.tof_min;
        this->peak_avg = point.peak_avg;
        this->peak_max = point.peak_max;
        this->peak_min = point.peak_min;
        this->tof_deviation = point.tof_deviation;
        return  *this;
    }
};

typedef struct
{
 int32_t tof_max;
 int32_t tof_min;
 int32_t peak_max;
 int32_t peak_min;
 int32_t line_k;
 int32_t line_b;
 //int weight;//权重 交叉区间最大值 减 最小值
}Tof_Para_Type;

struct array_modulus{
  double  k;
  double  b;
};

namespace HDTimer {

static inline qint64 getCurrentTimeMisc(){
    return QDateTime::currentDateTime().toMSecsSinceEpoch();
}
}

namespace pubFunc {
static inline uint16_t CRC16_MODBUS(uint8_t *p, uint32_t dlen)
{
    uint16_t CRC_Temp = 0xFFFF;
    uint32_t i, j;

    for(i = 0; i < dlen; i++)
    {
        CRC_Temp ^= p[i];
        for(j = 0; j < 8; j++)
        {
            CRC_Temp = (CRC_Temp&0x01)? ((CRC_Temp>>1)^0xA001) : (CRC_Temp>>1);
        }
    }
    return CRC_Temp;
}

inline QString ByteArrayToHexString(QByteArray data){
    QString ret(data.toHex().toUpper());//转为16进制大写
    int len = ret.length()/2;
    ret.insert(0,"0x");
    for(int i=1;i<len;i++)
    {
        ret.insert(4*i+i-1,",0x");//编写格式
    }
    return ret;
}
}

struct DTRPackageSend {
   uint8_t  siteID;
   uint8_t  funcCode;
   uint8_t  data_start_addr_high;
   uint8_t  data_start_addr_low;
   uint8_t  data_count_high;
   uint8_t  data_count_low;
   uint16_t crc_t;
};

#endif // CONFIG_H
