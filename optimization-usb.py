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
# /boot/config.txt
######################################################
 
boot = open('/boot/config.txt', 'r+')
boot.readlines()
# Imprime o conteudo

# Texto a ser inserido no arquivo
textboot = """          
# Corrente Maxima na porta USB
max_usb_current=1

"""                     # Termina o texto

boot.writelines(textboot)
boot.close() # Fecha o arquivo
print("\nAs portas USB do seu Pi foram configuradas para\nlimitar a voltagem a 1 volt.\n")
