 ldapsearch -Q "uid=z*" cn | grep cn: | cut -d : -f 2 | sort -fr | cut -c 2-