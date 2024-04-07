#!/bin/bash
dnf -v &> /dev/null
if [ $? -ne 0 ]; then
        yum install -y dnf &> /dev/null
fi
sudo yum -y install git cmake make gcc-c++ alsa-lib-devel mesa-libGL-devel libX11-devel libXrandr-devel libXi-devel libXcursor-devel libXinerama-devel
