#ifndef SSM_LIB_GLOBAL_H
#define SSM_LIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SSM_LIB_LIBRARY)
#  define SSM_LIB_EXPORT Q_DECL_EXPORT
#else
#  define SSM_LIB_EXPORT Q_DECL_IMPORT
#endif

#endif // SSM_LIB_GLOBAL_H
