dnl required version of autoconf
AC_PREREQ([2.69])

dnl TODO: fill in your package name and package version here
AC_INIT([amlhalasink],[1.0.0])

dnl required versions of gstreamer and plugins-base
GST_REQUIRED=1.0.0

AC_CONFIG_SRCDIR([src])
AC_CONFIG_HEADERS([config.h])

dnl required version of automake
AM_INIT_AUTOMAKE([1.10])

dnl enable mainainer mode by default
AM_MAINTAINER_MODE([enable])

dnl check for tools (compiler etc.)
AC_PROG_CC

dnl required version of libtool
LT_PREREQ([2.2.6])
LT_INIT

dnl give error and exit if we don't have pkgconfig
AC_CHECK_PROG(HAVE_PKGCONFIG, pkg-config, [ ], [
  AC_MSG_ERROR([You need to have pkg-config installed!])
])

dnl Check for the required version of GStreamer core (and gst-plugins-base)
dnl This will export GST_CFLAGS and GST_LIBS variables for use in Makefile.am
dnl
dnl If you need libraries from gst-plugins-base here, also add:
dnl for libgstaudio-1.0: gstreamer-audio-1.0 >= $GST_REQUIRED
dnl for libgstvideo-1.0: gstreamer-video-1.0 >= $GST_REQUIRED
dnl for libgsttag-1.0: gstreamer-tag-1.0 >= $GST_REQUIRED
dnl for libgstpbutils-1.0: gstreamer-pbutils-1.0 >= $GST_REQUIRED
dnl for libgstfft-1.0: gstreamer-fft-1.0 >= $GST_REQUIRED
dnl for libgstinterfaces-1.0: gstreamer-interfaces-1.0 >= $GST_REQUIRED
dnl for libgstrtp-1.0: gstreamer-rtp-1.0 >= $GST_REQUIRED
dnl for libgstrtsp-1.0: gstreamer-rtsp-1.0 >= $GST_REQUIRED
dnl etc.
PKG_CHECK_MODULES(GST, [
  gstreamer-1.0 >= $GST_REQUIRED
  gstreamer-base-1.0 >= $GST_REQUIRED
  gstreamer-audio-1.0 >= $GST_REQUIRED
], [
  AC_SUBST(GST_CFLAGS)
  AC_SUBST(GST_LIBS)
], [
  AC_MSG_ERROR([
      You need to install or upgrade the GStreamer development
      packages on your system. On debian-based systems these are
      libgstreamer1.0-dev and libgstreamer-plugins-base1.0-dev.
      on RPM-based systems gstreamer1.0-devel, libgstreamer1.0-devel
      or similar. The minimum version required is $GST_REQUIRED.
  ])
])

dnl check if compiler understands -Wall (if yes, add -Wall to GST_CFLAGS)
AC_MSG_CHECKING([to see if compiler understands -Wall])
save_CFLAGS="$CFLAGS"
CFLAGS="$CFLAGS -Wall"
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([ ], [ ])], [
  GST_CFLAGS="$GST_CFLAGS -Wall"
  AC_MSG_RESULT([yes])
], [
  AC_MSG_RESULT([no])
])

dnl set the plugindir where plugins should be installed (for src/Makefile.am)
if test "x${prefix}" = "x$HOME"; then
  plugindir="$HOME/.gstreamer-1.0/plugins"
else
  plugindir="\$(libdir)/gstreamer-1.0"
fi
AC_SUBST(plugindir)

AC_ARG_ENABLE([xrun-detection],
[  --enable-xrun-detection Turn on underrun detection],
[case "${enableval}" in
  yes) xrun=true ;;
  no)  xrun=false ;;
  *) AC_MSG_ERROR([bad value ${enableval} for --enable-xrun-detection]) ;;
esac],[xrun-detection=false])
AM_CONDITIONAL([XRUN], [test x$xrun = xtrue])

AC_ARG_ENABLE([ms12],
[  --enable-ms12 audio HAL is using ms12],
[case "${enableval}" in
  yes) ms12=true ;;
  no)  ms12=false ;;
  *) AC_MSG_ERROR([bad value ${enableval} for --enable-ms12]) ;;
esac],[ms12=false])
AM_CONDITIONAL([MS12], [test x${ms12} = xtrue])

AC_ARG_ENABLE([dts],
[  --enable-dts audio HAL is using dtsdecocder],
[case "${enableval}" in
  yes) dts=true ;;
  no)  dts=false ;;
  *) AC_MSG_ERROR([bad value ${enableval} for --enable-dts]) ;;
esac],[dts=false])
AM_CONDITIONAL([DTS], [test x${dts} = xtrue])

AC_ARG_ENABLE([essos-rm],
[  --enable-essos-rm Use essos for resource managing],
[case "${enableval}" in
  yes) essos=true ;;
  no)  essos=false ;;
  *) AC_MSG_ERROR([bad value ${enableval} for --enable-essos-rm]) ;;
esac],[essos=false])
AM_CONDITIONAL([ESSOS], [test x${essos} = xtrue])

AC_ARG_ENABLE([ad],
[  --enable-ad support audio description],
[case "${enableval}" in
  yes) ad=true ;;
  no)  ad=false ;;
  *) AC_MSG_ERROR([bad value ${enableval} for --enable-ad]) ;;
esac],[ad=false])
AM_CONDITIONAL([AD], [test x${ad} = xtrue])

AC_ARG_ENABLE([mediasync],
[  --enable-mediasync support media sync],
[case "${enableval}" in
  yes) mediasync=true ;;
  no)  mediasync=false ;;
  *) AC_MSG_ERROR([bad value ${enableval} for --enable-mediasync]) ;;
esac],[mediasync=false])
AM_CONDITIONAL([MEDIA_SYNC], [test x${mediasync} = xtrue])

dnl set proper LDFLAGS for plugins
GST_PLUGIN_LDFLAGS='-module -avoid-version -export-symbols-regex [_]*\(gst_\|Gst\|GST_\).*'
AC_SUBST(GST_PLUGIN_LDFLAGS)

AC_CONFIG_FILES([Makefile
  src/Makefile
  src/amlhalasink.pc
])
AC_OUTPUT

