#coding:utf-8
######################################################
#
# Otimização do sistema operacional no Pi para SVXLINK
#
######################################################
# Autor: Airam Saile
# Indicativo: PU8ASR / PX8C1730 / PP8004SWL
# E-Mail: airamcosta@gmail.com
# Site: http://conferenciaamazonica.wordpress.com
######################################################
 
######################################################
# /etc/fstab
######################################################
 
fstab = open('/etc/fstab', 'r+')
fstab.readlines()
#print conteudo

# Texto a ser inserido no arquivo
textfstab = """          
#temp filesystems for all the logging and stuff to keep it out of the SD card
tmpfs    /tmp    tmpfs    defaults,noatime,nosuid,size=100m    0 0
tmpfs    /var/tmp    tmpfs    defaults,noatime,nosuid,size=30m    0 0
tmpfs    /var/log    tmpfs    defaults,noatime,nosuid,mode=0755,size=100m    0 0
tmpfs    /var/spool/svxlink    tmpfs    defaults,noatime,nosuid,size=100m    0 0

"""                     # Termina o texto

fstab.writelines(textfstab)
fstab.close() # Fecha o arquivo
print("\nAlguns diretórios/pastas serão utilizados\nde forma temporária durante a execução do sistema.\nIsso evita que o espaço no SDCard seja rapidamente\nocupado com a crescente inserção de informações no\narquivo de log o que pode ocasionar inclusive a\ncorrupção de dados.")