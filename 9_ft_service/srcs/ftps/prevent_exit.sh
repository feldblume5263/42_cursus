#!/bin/sh
echo “Prevent exit container”
/bin/sh # livenessProbe에서 vsftps를 감지할 것 같으니, 계속 사용해도 될 것 같음
