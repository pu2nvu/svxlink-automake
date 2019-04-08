#coding:utf-8
######################################################
#
# Assistente de Configuração do SVXLINK no Pi
#
######################################################
# Autor: Airam Saile
# Indicativo: PU8ASR / PX8C1730 / PP8004SWL
# E-Mail: airamcosta@gmail.com
# Site: http://conferenciaamazonica.wordpress.com
######################################################
 
######################################################
# /etc/svxlink/svxlink.conf
# /etc/svxlink/svxlink.d/ModuleEchoLink.conf
# /etc/rc.local
######################################################

# Arquivos que serão editados com este script
svxlink = "/etc/svxlink/svxlink.conf"
ModuleEchoLink = "/etc/svxlink/svxlink.d/ModuleEchoLink.conf"
start = "/etc/rc.local"

# Perguntas básicas para realizar a configuração
qra = raw_input("   Qual seu nome? ")
qra = qra.upper()
callsign = raw_input("   Qual seu indicativo? ")
callsign = callsign.upper()
password = raw_input("   Informe sua senha do EchoLink: ")
qth = raw_input("   Informe sua cidade e sigla do estado. Ex: Manaus/AM ")
qth = qth.upper()
print("   A legislação determina que links do Echolink obrigatoriamente\n   devem ocupar frequências entre 145.015 e 145.195 com intervalos\n   de 0.015")
print("   Para a próxima pergunta, observe o exemplo")
qrg = raw_input("   Informe a QRG de operação. Ex: 145.015 ")
print("   Para a próxima pergunta, observe o exemplo")
ctcss = raw_input("   Informe o Subtom ou deixe em branco se não houver. Ex: 67.0 ")
transceiver = raw_input("   Informe o fabricante/modelo do seu transceptor: ")
transceiver = transceiver.upper()
antenna = raw_input("   Informe o fabricante/modelo da sua antena: ")
antenna = antenna.upper()

# Função que configura no boot as portas GPIO e o início automático do SVXLINK em segundo plano
def boot_daemon():
	# rc.local
	with open(start, 'U') as f:
		newText=f.read()
		while 'exit 0' in newText:
			newText=newText.replace('exit 0', '')
	with open(start, "w") as f:
		f.write(newText)

	# Acrescenta ostras configurações
	initial = open(start, 'r+')
	initial.readlines()
	# Imprime o conteudo

	# Texto a ser inserido no arquivo
	startconfig = """# Configurações GPIO paraacionamento do PTT
# PTT GPIO17 (pino 11) -- Éselecionado o pino 11
# porque o pino 9 é GND (e fica ao lado do 11)
echo 17 > /sys/class/gpio/export
echo 'out' > /sys/class/gpio/gpio17/direction
echo 0 > /sys/class/gpio/gpio17/value

#Substitui /var/spool/svxlink que é temporário.
cd /var/spool
tar zxvf svxlink.tgz

# Dá permissão de escrita na pasta voice_mail
sudo chmod 777 /var/spool/svxlink/voice_mail

# Dá permissão de escrita para manipular os arquivos de log do svxlink
# Esta permissão é necessária para o comando seguinte ao comando abaixo
sudo chmod 777 /var/log/svxlink*

# Iniciando o svxlink como servico (oculto)
svxlink --daemon --logfile=/var/log/svxlink.log>&1 | tee -a /var/log/svxlink_live.$(date '+%Y%m%d').log

exit 0"""                     # Fim o texto a ser inserido no arquivo

	initial.writelines(startconfig)
	initial.close() # Fecha o arquivo

# Função que configura no boot as portas GPIO e o início automático do SVXLINK
def boot():
	# rc.local
	with open(start, 'U') as f:
		newText=f.read()
		while 'exit 0' in newText:
			newText=newText.replace('exit 0', '')
	with open(start, "w") as f:
		f.write(newText)

	# Acrescenta ostras configurações
	initial = open(start, 'r+')
	initial.readlines()
	# Imprime o conteudo

	# Texto a ser inserido no arquivo
	startconfig = """# Configurações GPIO paraacionamento do PTT
# PTT GPIO17 (pino 11) -- Éselecionado o pino 11
# porque o pino 9 é GND (e fica ao lado do 11)
echo 17 > /sys/class/gpio/export
echo 'out' > /sys/class/gpio/gpio17/direction
echo 0 > /sys/class/gpio/gpio17/value

#Substitui /var/spool/svxlink que é temporário.
cd /var/spool
tar zxvf svxlink.tgz

# Dá permissão de escrita na pasta voice_mail
sudo chmod 777 /var/spool/svxlink/voice_mail

# Iniciando o svxlink
svxlink

exit 0"""                     # Fim o texto a ser inserido no arquivo

	initial.writelines(startconfig)
	initial.close() # Fecha o arquivo

# Chama a atenção do usuário para escolher se deseja ou não visualizar o status do EchoLink durante a inicialização/execução do sistema
def daemon_attention():
	print("\n   Você não informou uma opção válida!\n   Todo o esforço para desenvolver um sistema e você ainda consegue fazer errado?!\n   Presta atenção pelo amor de Deus...\n")
	type()

# Verifica se o usuário deseja visualizar o status do EchoLink durante a inicialização/execução do sistema
def daemon():
	print("\n   A configuração a seguir é visível somente se você usar seu\n   Pi exclusivamente em modo de terminal e refere-se a exibição\n   ou não do status do EchoLink durante a execução/início do sistema.\n")
	print("   Deseja visualizar o status do EchoLink durante sua execução?\n")
	ver = raw_input("   Informe S para SIM ou N para NÃO: ")
	ver = ver.upper()
	#Verifica a resposta do usuário
	if (ver == "S"):
		#Chama a função que configura a execução sem exibição de status (Daemon)
		boot()
	else:
		if (ver == "N"):
			#Chama a função que configura a execução com exibição de status
			boot_daemon()
		else:
			#Chama a atenção do usuário para ele prestar atenção
			daemon_attention()

# Chama a atenção do usuário na escolha do tipo de estação que está sendo configurada
def attention_autoconnect():
	print("\n   Você não informou uma opção válida!\n   Parece que você não esta prestando atenção.\n   Todo o esforço para desenvolver um sistema e você ainda consegue fazer errado?!\n   Este assistente não advinha, portanto, presta atenção!\n")
	autoconnect()

# Definindo ou não configurações de autoconexão
def autoconnect():
	print("   Deseja se conectar automaticamente em alguma conferência/estação?")
	autoconnect = raw_input("   Informe S para Link ou N para Repetidor: ")
	autoconnect = autoconnect.upper()
	#Verifica a resposta do usuário
	if (autoconnect == "S"):
		# Instruções ao usuário
		print("   Os números de nó do Echolink são compostos apenas de números.\n   São aqueles números que você usa para se conectar\n   através de comandos DTMF pelo teclado do rádio.")
		print("   Por exemplo, o número de nó da Conferência *AMAZON* é 362210")
		print("   Os números de nó de todas as estações do EchoLink podem ser\n   obitidos em https://secure.echolink.org/logins.jsp")
		# Solicita entrada
		nodenumber = raw_input("   Informe o número do nó que deseja se conectar no EchoLink: ")
		nodenumber = nodenumber.upper()
		# Edita o arquivo
		# ModuleEchoLink.conf
		with open(ModuleEchoLink, 'U') as f:
			newText=f.read()
			while '#AUTOCON_ECHOLINK_ID=' in newText:
				newText=newText.replace('#AUTOCON_ECHOLINK_ID=', 'AUTOCON_ECHOLINK_ID=')
			while '9999' in newText:
				newText=newText.replace('9999', nodenumber)
		with open(ModuleEchoLink, "w") as f:
			f.write(newText)
		print("\n   A configuração de autoconexão para o nó do EchoLink informado foi concluída!\n   Aguarde...\n")
	else:
		if (autoconnect == "N"):
			# ModuleEchoLink.conf
			with open(ModuleEchoLink, 'U') as f:
				newText=f.read()
				while '#ALLOW_IP' in newText:
					newText=newText.replace('#ALLOW_IP', 'ALLOW_IP')
				while '#ACCEPT_INCOMING' in newText:
					newText=newText.replace('#ACCEPT_INCOMING', 'ACCEPT_INCOMING')
			with open(ModuleEchoLink, "w") as f:
				f.write(newText)
			print("\n   Configuração concluida!\n   Sua estação poderá receber até 10 conexões simultâneas.\n   Aguarde...\n")
		else:
			attention_autoconnect()

# Chama a atenção do usuário na escolha do tipo de estação que está sendo configurada
def attention_type():
	print("\n   Você não informou uma opção válida!\n   Todo o esforço para desenvolver um sistema e você ainda consegue fazer errado?!\n   Presta atenção pelo amor de Deus...\n")
	type()

# Verifica se é um Link ou Repetidor
def type():
	print("   Você está configurando um LINK ou um REPETIDOR?")
	type = raw_input("   Informe L para Link ou R para Repetidor: ")
	type = type.upper()
	#Verifica a resposta do usuário
	if (type == "L"):
		# Edita os arquivos

		# svxlink.conf
		with open(svxlink, 'U') as f:
			newText=f.read()
			while 'LOGICS=RepeaterLogic' in newText:
				newText=newText.replace('LOGICS=RepeaterLogic', 'LOGICS=SimplexLogic')
			while 'MYCALL' in newText:
				newText=newText.replace('MYCALL', callsign)
			while 'alsa:plughw:0' in newText:
				newText=newText.replace('alsa:plughw:0', 'alsa:plughw:1')
			while 'PTT_PORT=/dev/ttyS0' in newText:
				newText=newText.replace('PTT_PORT=/dev/ttyS0', 'PTT_PORT=GPIO')
			while 'PTT_PIN=DTRRTS' in newText:
				newText=newText.replace('PTT_PIN=DTRRTS', 'PTT_PIN=gpio17')
		with open(svxlink, "w") as f:
			f.write(newText)

		# ModuleEchoLink.conf
		with open(ModuleEchoLink, 'U') as f:
			newText=f.read()
			while 'MYCALL' in newText:
				newText=newText.replace('MYCALL', callsign)
			while '-R' in newText:
				newText=newText.replace('-R', '-L')
			while 'MyPass' in newText:
				newText=newText.replace('MyPass', password)
			while 'MyName' in newText:
				newText=newText.replace('MyName', qth + ' ' + qrg + ' ' + ctcss)
			while '[Svx] Fq, MyTown' in newText:
				newText=newText.replace('[Svx] Fq, MyTown', qth + ' ' + qrg + ' ' + ctcss)
			while 'You have connected to a SvxLink node' in newText:
				newText=newText.replace('You have connected to a SvxLink node', 'Você está conectado a um dispositivo Pi com SVXLINK')
			while 'a voice services system for Linux with EchoLink' in newText:
				newText=newText.replace('a voice services system for Linux with EchoLink', 'um sistema de suporte a voz sobre IP para')
			while 'support.' in newText:
				newText=newText.replace('support.', 'Linux com EchoLink de propriedade de XXX')
			while 'Check out http://svxlink.sf.net/ for more info' in newText:
				newText=newText.replace('Check out http://svxlink.sf.net/ for more info', 'Acesse https://goo.gl/MGqJ5t para mais informações')
			while 'My_QTH' in newText:
				newText=newText.replace('My_QTH', qth)
			while 'Simplex link on ???.???' in newText:
				newText=newText.replace('Simplex link on ???.???', qrg)
			while 'My_CTCSS_fq_if_any' in newText:
				newText=newText.replace('My_CTCSS_fq_if_any', ctcss)
			while 'My_transceiver_type' in newText:
				newText=newText.replace('My_transceiver_type', transceiver)
			while 'My_antenna_brand/type/model' in newText:
				newText=newText.replace('My_antenna_brand/type/model', antenna)
		with open(ModuleEchoLink, "w") as f:
			f.write(newText)

		# ModuleEchoLink.conf - Configuração adicional que insere o QRA nas informações do nó
		with open(ModuleEchoLink, 'U') as f:
			newText=f.read()
			while 'XXX' in newText:
				newText=newText.replace('XXX', qra)
		with open(ModuleEchoLink, "w") as f:
			f.write(newText)

		# Chama a função que irá escrever as configurações de boot
		daemon()

		print("\n   Seu link está configurado para acionar o PTT utilizando a porta\n   GPIO 17 (pinos 11 e 9).\n   Seu Raspberry se conectará no sistema EchoLink quando você ligá-lo.\n")

	else:
		if (type == "R"):
			# Edita os arquivos

			# svxlink.conf
			with open(svxlink, 'U') as f:
				newText=f.read()
				while 'LOGICS=SimplexLogic' in newText:
					newText=newText.replace('LOGICS=SimplexLogic', 'LOGICS=RepeaterLogic')
				while 'MYCALL' in newText:
					newText=newText.replace('MYCALL', callsign)
				while 'alsa:plughw:0' in newText:
					newText=newText.replace('alsa:plughw:0', 'alsa:plughw:1')
				while 'PTT_PORT=/dev/ttyS0' in newText:
					newText=newText.replace('PTT_PORT=/dev/ttyS0', 'PTT_PORT=GPIO')
				while 'PTT_PIN=DTRRTS' in newText:
					newText=newText.replace('PTT_PIN=DTRRTS', 'PTT_PIN=gpio17')
			with open(svxlink, "w") as f:
				f.write(newText)

			# ModuleEchoLink.conf
			with open(ModuleEchoLink, 'U') as f:
				newText=f.read()
				while 'MYCALL' in newText:
					newText=newText.replace('MYCALL', callsign)
				while '-L' in newText:
					newText=newText.replace('-L', '-R')
				while 'MyPass' in newText:
					newText=newText.replace('MyPass', password)
				while 'MyName' in newText:
					newText=newText.replace('MyName', qth + ' ' + qrg + ' ' + ctcss)
				while '[Svx] Fq, MyTown' in newText:
					newText=newText.replace('[Svx] Fq, MyTown', qth + ' ' + qrg + ' ' + ctcss)
				while 'You have connected to a SvxLink node' in newText:
					newText=newText.replace('You have connected to a SvxLink node', 'Você está conectado a um dispositivo Pi com SVXLINK')
				while 'a voice services system for Linux with EchoLink' in newText:
					newText=newText.replace('a voice services system for Linux with EchoLink', 'um sistema de suporte a voz sobre IP para')
				while 'support.' in newText:
					newText=newText.replace('support.', 'Linux com EchoLink de propriedade de XXX')
				while 'Check out http://svxlink.sf.net/ for more info' in newText:
					newText=newText.replace('Check out http://svxlink.sf.net/ for more info', 'Acesse https://goo.gl/MGqJ5t para mais informações')
				while 'My_QTH' in newText:
					newText=newText.replace('My_QTH', qth)
				while 'Simplex link on ???.???' in newText:
					newText=newText.replace('Simplex link on ???.???', qrg)
				while 'My_CTCSS_fq_if_any' in newText:
					newText=newText.replace('My_CTCSS_fq_if_any', ctcss)
				while 'My_transceiver_type' in newText:
					newText=newText.replace('My_transceiver_type', transceiver)
				while 'My_antenna_brand/type/model' in newText:
					newText=newText.replace('My_antenna_brand/type/model', antenna)
			with open(ModuleEchoLink, "w") as f:
				f.write(newText)

			# ModuleEchoLink.conf - Configuração adicional que insere o QRA nas informações do nó
			with open(ModuleEchoLink, 'U') as f:
				newText=f.read()
				while 'XXX' in newText:
					newText=newText.replace('XXX', qra)
			with open(ModuleEchoLink, "w") as f:
				f.write(newText)

			# Chama a função que irá escrever as configurações de boot
			daemon()

			print("\n   Seu repetidor está configurado para acionar o PTT utilizando a porta\n   GPIO 17 (pinos 11 e 9).\n   Seu Raspberry se conectará no sistema EchoLink quando você ligá-lo.\n")

		else:
			attention_type()

# Inicia o programa chamando a 1ª função
type()
# Chama a 2º função que determina a autoconexão ou apenas em modo stand-by limitando a quantidade de conexões de entrada
autoconnect()