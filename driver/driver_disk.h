#ifndef DRIVER_DISK_H
#define DRIVER_DISK_H
#include <windows.h>
#include <QString>

namespace driver {

class Disk
{
public:

  /***********************************************************************************
   * ����: quint64 freeSpace(const QString &driver)
   * ����: ��ȡwindows������ʣ���С
   * ����: const QString &driver: ���̷�,����: "C:/"
   * ����: ����ʣ����ֽ���
   * *********************************************************************************/
  static quint64 freeSpace(const QString &driver){
    LPCWSTR lpcwstrDriver=(LPCWSTR)driver.utf16();
    ULARGE_INTEGER liFreeBytesAvailable, liTotalBytes, liTotalFreeBytes;
    if( !GetDiskFreeSpaceEx( lpcwstrDriver, &liFreeBytesAvailable, &liTotalBytes, &liTotalFreeBytes) ){
      //qDebug() << "ERROR: Call to GetDiskFreeSpaceEx() failed.";
      return 0;
    }
    return (quint64) liTotalFreeBytes.QuadPart;
  }
protected:
  Disk(){
  }
};
}
#endif // DRIVER_DISK_H
