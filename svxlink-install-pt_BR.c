/* Autor: Airam - PU8ASR/PX8C1730/PP8004SWL */
/* Conferência Amazônica de Radioamadorismo e Rádio do Cidadão */
/* http://conferenciaamazonica.wordpress.com */
/* airamcosta@gmail.com */
/* Contribuições são bem-vindas! */

#include<stdio.h>
#include<stdlib.h>
#include<locale.h> //necessário para usar setlocale

#define TEMP 30 //Contador de tempo para tela de abertura (15 segundos)
#define TMP 5 //Contador de tempo para mensagens (5 segundos)

/* Início dos protótipos */
void limpa_tela();
void limpa_tela_cabecalho();
void cabecalho_menu_principal();
void imprime_tela_abertura();
int fileExists(char *cpfileName);
int decision2Options(); // Variável que recebe a decisão do usuário em relação aos backup dos arquivos
/* Fim dos protótipos */

/* Início dos códigos de tela */
/* Limpa a tela */
void limpa_tela()
{
    system("clear");
}

/* Cabeçalho do programa */
void imprime_tela_cabecalho()
{
    limpa_tela();
    printf("\n");
    printf("   Desenvolvimento de Software da Conferência Amazônica           by PU8ASR\n");
    printf("  ##########################################################################\n");
    printf("                             INSTALADOR DO SVXLINK\n");
    printf("                       (sempre a última versão no seu Pi)\n");
    printf("  ##########################################################################\n");
}

/* Cabeçalho do menu principal */
void cabecalho_menu_principal()
{
	sleep(TMP);
    imprime_tela_cabecalho();
    printf("  ================================== MENU ==================================\n\n");
}

/* Imprime o texto sobre o programa na tela de abertura */
void imprime_tela_abertura()
{
    imprime_tela_cabecalho();
    printf("   Este software foi desenvolvido para facilitar o processo de instalação e\n");
    printf("   configuração do SVXLINK (Echolink para Linux) criado por Tobias Blomberg,\n");
    printf("   radioamador com o indicativo SM0SVX.\n\n");
    printf("   Este software tem por objetivo, instalar sempre a versão mais recente do\n");
    printf("   SVXLINK no seu dispositivo Pi, otimizando todo o processo de instalação\n");
    printf("   e configuração.\n\n");
    printf("   Este software é protegido pela Lei de Direitos Autorais e de Propriedade\n");
    printf("   Intelectual. Não pode ser vendido ou comercializado. Sua distribuição é\n");
    printf("   gratuita e o código-fonte é disponibilizado sob os termos de licença\n");
    printf("   GNU/Linux 3.0 e distribuíbo exclusivamente pelo site github.com.\n\n"); //Se ativar a linha abaixo remover \n\n\n\n\n\n\n (7)
    printf("   Autor: Airam - PU8ASR (airamcosta@gmail.com)\n\n");
    printf("   O menu será exibido em %d segundos\n", TEMP);
	sleep(TEMP);
}
/* Fim dos códigos de tela */

/* Início do código que verifica a existência de arquivos necessários nas configurações */
int fileExists(char *cpfileName)
{
    FILE *file = fopen(cpfileName, "r");
    if (!file)
        return 0; /* não existe */
    return 1; /* existe */
}
/* Fim do código que verifica a existência de arquivos necessários nas configurações */

/* Início do código onde o usuário terá que fazer escolhas */
int decision2Options()
{
    int Op; //Variável que receberá a escolha do usuário

    fflush(stdin); //Limpa o buffer do teclado para evitar erros
    printf("   Digite 1 para Sim ou 0 para Não: ");
    scanf("%d", &Op); //Aguarda a escolha do usuário
    getchar(); //Realiza uma pausa para que dê tempo para o usuário inserir a opção

    return Op;
}
/* Fim do código onde o usuário terá que fazer escolhas */

/* Incício do corpo principal da aplicação */
int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    imprime_tela_abertura(); //Imprime o cabeçalho da aplicação

    int Opt; //Variável que recebe o comando do usuário (Menu)
    do
    {
        cabecalho_menu_principal(); //Imprime o cabeçalho do menu após o tempo definido na constante TEMP

        //menu_principal(); //Imprime o menu principal na tela

        printf("                       1 - Remover PulseAudio\n");
        printf("                       2 - Atualizar Sistema\n");
        printf("                       3 - Atualizar Firmware\n");
        printf("                       4 - Adicionar usuário SVXLINK\n");
        printf("                       5 - Instalar Dependências\n");
        printf("                       6 - Otimizar Sistema\n");
        printf("                       7 - Instalar SVXLINK\n");
        printf("                       8 - Configurar SVXLINK\n");
        printf("                       9 - Esquema de ligação ao Transceptor\n");
        printf("                      10 - Ajuda\n");
        printf("                      11 - Portal da Conferência Amazônica\n");
        printf("                       0 - Sair\n\n\n");

        printf("   Informe a opção: ");

        scanf("%d", &Opt);

		fflush(stdin); //Limpa o bufer de teclado evitando erros na coleta dos próximos comandos

        if (Opt == 1)
        {
			imprime_tela_cabecalho(); //Imprime o cabeçalho da aplicação

			printf("  ======================== REMOCAO DO PULSE AUDIO ==========================\n\n");

			printf("   O PulseAudio apresenta problemas de incompatibilidade. Por isso, faz-se\n");
			printf("   necessaário removê-lo para que o AlsaMixer seja instalado posteriormente\n");
			printf("   na opção 5 - Instalar Dependências\n\n");

			sleep(TMP);

			system("sudo apt-get purge pulseaudio gstreamer0.10-pulseaudio pulseaudio-utils");
        }

        if (Opt == 2)
        {
			imprime_tela_cabecalho(); //Imprime o cabeçalho da aplicação

			printf("  ========================= ATUALIZAÇÃO DO SISTEMA =========================\n\n");

			printf("   A partir de agora será iniciado o processo de download e instalação dos\n");
			printf("   componentes mais recentes para o seu sistema operacional.\n");
			printf("   Ao final do procedimento seu dispositivo Pi  será reiniciado.\n");
			printf("   Para continuar os passos seguintes, repita o processo descrito no site\n");
			printf("   para iniciar novamente o instalador...\n\n");

			sleep(TMP);

			system("sudo apt-get update && sudo apt-get upgrade && sudo reboot");
        }

        else if (Opt == 3)
        {
			imprime_tela_cabecalho(); //Imprime o cabeçalho da aplicação

			printf("  ========================= ATUALIZAÇÃO DO FIRMWARE ========================\n\n");

			printf("   A partir de agora será iniciado o processo de download e instalação do\n");
			printf("   seu hardware. É importante não interromper este processo para evitar a\n");
			printf("   inutilizacao do seu equipamento.\n");
			printf("   Seu dispositivo será automaticamente reiniciado ao final do processo.\n");
			printf("   Para continuar os passos seguintes, repita o processo descrito no site\n");
			printf("   para iniciar novamente o instalador...\n\n");

			sleep(TMP);

			system("sudo UPDATE_SELF=0 rpi-update && sudo reboot");
        }

        else if (Opt == 4)
        {
			imprime_tela_cabecalho(); //Imprime o cabeçalho da aplicação

			printf("  ============================== SVXLINK USER ==============================\n\n");

			printf("   O usuário svxlink é o responsável pela execução do software svxlink,\n");
			printf("   destinando o usuário pi(root) para fins mais importantes.\n");
			printf("   É necessário criá-lo(caso o mesmo não exista neste sistema).\n\n");

			sleep(TMP);

			system("sudo useradd -c \"Usuário Echolink\" -G gpio,audio -d /home/svxlink -m -s /sbin/nologin svxlink");
        }

        else if (Opt == 5)
        {
			imprime_tela_cabecalho(); //Imprime o cabeçalho da aplicação

			printf("  ======================= INSTALAÇÃO DE DEPENDÊNCIAS =======================\n\n");

			printf("   Para que o SVXLINK funcione corretamente, é necessario que alguns itens\n");
			printf("   estejam presentes em seu sistema.\n\n");
			printf("   Os seguintes itens serão instalados e caso já existam, serão atualizados:\n");
			printf("   g++ make libgsm1-dev libpopt-dev tcl8.5-dev libgcrypt-dev libspeex-dev\n");
			printf("   libasound2-dev alsa-utils libqt4-dev cmake libsigc++-2.0-dev\n");
			printf("   libgcrypt11-dev tk-dev libopus-dev groff\n\n");

			sleep(TMP);

			system("sudo apt-get install g++ make libgsm1-dev libpopt-dev tcl8.5-dev libgcrypt-dev libspeex-dev libasound2-dev alsa-utils libqt4-dev cmake libsigc++-2.0-dev libgcrypt11-dev tk-dev libopus-dev groff --force-yes");

			sleep(TMP);

			printf("\n   Terminado!\n");
        }

        else if (Opt == 6)
        {
			imprime_tela_cabecalho(); //Imprime o cabeçalho da aplicação

			printf("  ========================== OTIMIZAÇÃO DO SISTEMA =========================\n\n");

			printf("   Algumas configurações serão feitas automaticamente para possibilitar que\n");
			printf("   o seu dispositivo utilize racionalmente os recursos, promovendo um\n");
			printf("   consumo mais eficiente de hardware, software e energia.\n\n");

			sleep(TMP);
		
			printf("   Removendo programas desnecessários e não utilizados...\n");

			system("sudo apt-get autoremove");

			sleep(TMP);

			printf("   \nVerificando a existência de cópia de segurança...\n");

			if (fileExists("/etc/fstab.bkp")==1)
			{
				printf("   O arquivo fstab já foi alterado anteriormente.\n");
				printf("   Deseja restaurar a cópia do arquivo original?\n");

				if(decision2Options()==1)
				{
					printf("   Restaurando a cópia arquivo original...\n");
					system("sudo cp /etc/fstab.bkp /etc/fstab");
					printf("   A cópia não é mais necessária. Removendo...\n");
					system("sudo rm /etc/fstab.bkp");
					printf("   Concluído!\n");
				};
			};
			
			if(fileExists("/boot/config.txt.bkp")==1)
			{
				printf("   O arquivo config.txt já foi alterado anteriormente.\n");
				printf("   Deseja restaurar a cópia do arquivo original?\n");

				if(decision2Options()==1)
				{
					printf("   Restaurando a cópia do arquivo original...\n");
					system("sudo cp /boot/config.txt.bkp /boot/config.txt");
					printf("   A cópia não é mais necessária. Removendo...\n");
					system("sudo rm /boot/config.txt.bkp");
					printf("   Concluído!\n");
				};
			};
			
			if(fileExists("/etc/fstab.bkp")==0)
			{
				printf("   Não foi encontrada nenhuma cópia de segurança de /etc/fstab\n");
				printf("   Criando cópia de segurança do arquivo /etc/fstab\n");
				system("sudo cp /etc/fstab /etc/fstab.bkp");
				printf("   Otimizando partições...\n");
				system("sudo python optimization-partitions.py");
				printf("   Desativando SWAP...\n");
				system("sudo swapoff --all");
				printf("   Removendo SWAP...\n");
				system("sudo apt-get remove dphys-swapfile");
				printf("   Concluído!\n\n");
				
				printf("   Deseja abrir o arquivo para visualizar as alterações ou editá-lo.\n");
				if(decision2Options()==1)
				{
					system("sudo nano /etc/fstab");
				};
			};			
			
			if(fileExists("/boot/config.txt.bkp")==0)
			{
				printf("   Não foi encontrada nenhuma cópia de segurança de /boot/config.txt\n");
				printf("   Criando cópia de segurança do arquivo /boot/config.txt\n");
				system("sudo cp /boot/config.txt /boot/config.txt.bkp");
				printf("   Configurando tensão nas portas USB...\n");
				system("sudo python optimization-usb.py");
				printf("   Concluído!\n\n");
				
				printf("   Deseja abrir o arquivo para visualizar as alterações ou editá-lo.\n");
				if(decision2Options()==1)
				{
					system("sudo nano /boot/config.txt");
				};
			};

			printf("\n\n   Terminado!\n\n");
        }

        else if (Opt == 7)
        {
			imprime_tela_cabecalho(); //Imprime o cabeçalho da aplicação

			printf("  ========================== INSTALAÇÃO DO SVXLINK =========================\n\n");

			printf("   A partir de agora será iniciado o processo de download e instalação do\n");
			printf("   SVXLINK, bem como dos arquivos de audio 13.12(no idioma Inglês dos\n");
			printf("   Estados Unidos).\n");
			printf("   É um processo demorado mas fique tranquilo!\n");
			printf("   Assim que estiver concluído, você visualizará o menu principal novamente\n");
			printf("   e poderá prosseguir com a configuração.\n\n");

			sleep(TMP);

			system("cd /home/pi/Downloads");
			
			if(fileExists("master.tar.gz")==0)
			{
				printf("   Iniciando download dos arquivos de instalação...\n\n");
				system("wget https://github.com/sm0svx/svxlink/archive/master.tar.gz");
				printf("\n\n   Arquivo master.tar.gz baixado com sucesso em /home/pi/Downloads\n");
			} else
				if(fileExists("master.tar.gz")==1)
				{
					printf("   Arquivos de instalação detectados em /home/pi/Downloads...\n\n");
				};
			
			printf("   Iniciando descompactação...\n\n");
			system("tar -xvzf master.tar.gz");
			printf("\n\n   Descompactação concluída!\n");
			printf("   Iniciando instalação...\n\n");
			printf("\n\n   Criando diretório de compilação...\n\n");
			system("mkdir /home/pi/Downloads/svxlink-master/src/build");
			printf("\n\n   Diretório de compilação criado!\n");
			printf("\n\n   Compilando arquivos de instalação...\n\n");
			system("cd /home/pi/Downloads/svxlink-master/src/build && cmake -DCMAKE_INSTALL_PREFIX=/usr -DSYSCONF_INSTALL_DIR=/etc -DLOCAL_STATE_DIR=/var -DUSE_OSS=NO -DUSE_QT=NO .. && make && make doc && sudo ldconfig && sudo make install");
			printf("\n\n   Compilação concluída!\n");
			printf("\n\n   Configurando SWAP para SVXLINK...\n\n");
			system("cd /var/spool && sudo chmod 777 svxlink && sudo tar zcvf svxlink.tgz svxlink"); //Com o swap desativado o diretório do svxlink será apagado no boot e precisará ser reestabelecido
			printf("\n\n   Instalando arquivos de áudio do SVXLINK\n\n");
			
			if(fileExists("/home/pi/Downloads/svxlink-sounds-en_US-heather-16k-13.12.tar.bz2")==0)
			{
				system("cd /home/pi/Downloads && wget https://github.com/sm0svx/svxlink-sounds-en_US-heather/releases/download/14.08/svxlink-sounds-en_US-heather-16k-13.12.tar.bz2 && tar -jxvf svxlink-sounds-en_US-heather-16k-13.12.tar.bz2 && sudo mkdir /usr/share/svxlink/sounds/en_US && cd en_US-heather-16k && sudo cp -r * /usr/share/svxlink/sounds/en_US");
			} else
				if(fileExists("/home/pi/Downloads/svxlink-sounds-en_US-heather-16k-13.12.tar.bz2")==1)
				{
					system("cd /home/pi/Downloads && tar -jxvf svxlink-sounds-en_US-heather-16k-13.12.tar.bz2 && sudo mkdir /usr/share/svxlink/sounds/en_US && cd en_US-heather-16k && sudo cp -r * /usr/share/svxlink/sounds/en_US");
				};
			
			if(fileExists("/home/pi/Downloads/sounds-svxlink-16k-pt_BR-HELENA.tar.bz2")==0)
			{
				system("cd /home/pi/Downloads && wget https://github.com/pu8asr/svxlink-automake/raw/master/sounds-svxlink-16k-pt_BR-HELENA.tar.bz2 && tar -jxvf sounds-svxlink-16k-pt_BR-HELENA.tar.bz2 && cd en_US && sudo cp -r * /usr/share/svxlink/sounds/en_US");
			} else
				if(fileExists("/home/pi/Downloads/sounds-svxlink-16k-pt_BR-HELENA.tar.bz2")==1)
				{
					system("cd /home/pi/Downloads && tar -jxvf sounds-svxlink-16k-pt_BR-HELENA.tar.bz2 && cd en_US && sudo cp -r * /usr/share/svxlink/sounds/en_US");
				};

			printf("\n\n   SVXLINK instalado e pronto para ser configurado!\n");
			printf("\n\n   Os arquivos da instalação não são mais necessários.\n");
			printf("\n\n   Deseja excluílos e liberar espaço?.\n");
			if(decision2Options()==1)
				{
					printf("   Iniciando exclusão...\n");
					system("cd /home/pi/Downloads");
					printf("   Excluindo svxlink-sounds-en_US-heather-16k-13.12.tar.bz2\n");
					system("rm svxlink-sounds-en_US-heather-16k-13.12.tar.bz2");
					printf("\n\n   Exclusão concluida!\n");
					printf("   Excluindo en_US-heather-16k\n");
					system("rm -r en_US-heather-16k");
					printf("\n\n   Exclusão concluida!\n");
					printf("   Excluindo sounds-svxlink-16k-pt_BR-HELENA.tar.bz2\n");
					system("rm sounds-svxlink-16k-pt_BR-HELENA.tar.bz2");
					printf("\n\n   Exclusão concluida!\n");
					printf("   Excluindo en_US\n");
					system("rm -r en_US");
					printf("\n\n   Exclusão concluida!\n");
					printf("   Excluindo svxlink-master\n");
					system("sudo rm -r svxlink-master");
					printf("\n\n   Exclusão concluida!\n");
					sleep(TMP);
				} else printf("\n\n   Os arquivos e pastas serão mantidos em /home/pi/Downloads\n   Instalação concluída. Aguarde...\n   Retornando ao menu principal...\n");
					
        }

        else if (Opt == 8)
        {
			if(fileExists("/etc/svxlink/svxlink.conf.bkp")==1)
			{
				imprime_tela_cabecalho(); //Imprime o cabeçalho da aplicação
				printf("  ========================= CONFIGURAÇÃO DO SVXLINK ========================\n\n");
				printf("   O assistente o ajudará a configurar o seu LINK ou REPETIDOR.\n\n");
				printf("   Verificando a existência de cópia de segurança...\n");
				
				printf("   O arquivo svxlink.conf já foi alterado anteriormente.\n");
				printf("   Deseja restaurar a cópia original do arquivo?\n");
				if(decision2Options()==1)
				{
					printf("   Restaurando a cópia arquivo original...\n");
					system("sudo cp /etc/svxlink/svxlink.conf.bkp /etc/svxlink/svxlink.conf");
					printf("   A cópia não é mais necessária. Removendo...\n");
					system("sudo rm /etc/svxlink/svxlink.conf.bkp");
					printf("   Concluído!\n");
				};
			};
			
			if(fileExists("/etc/svxlink/svxlink.d/ModuleEchoLink.conf.bkp")==1)
			{
				imprime_tela_cabecalho(); //Imprime o cabeçalho da aplicação
				printf("  ========================= CONFIGURAÇÃO DO SVXLINK ========================\n\n");
				printf("   O assistente o ajudará a configurar o seu LINK ou REPETIDOR.\n\n");
				printf("   Verificando a existência de cópia de segurança...\n");
					
				printf("   O arquivo ModuleEchoLink.conf já foi alterado anteriormente.\n");
				printf("   Deseja restaurar a cópia original do arquivo?\n");
				if(decision2Options()==1)
				{
					printf("   Restaurando a cópia do arquivo original...\n");
					system("sudo cp /etc/svxlink/svxlink.d/ModuleEchoLink.conf.bkp /etc/svxlink/svxlink.d/ModuleEchoLink.conf");
					printf("   A cópia não é mais necessária. Removendo...\n");
					system("sudo rm /etc/svxlink/svxlink.d/ModuleEchoLink.conf.bkp");
					printf("   Concluído!\n");
				};
			};
			
			if(fileExists("/etc/rc.local.bkp")==1)
			{
				imprime_tela_cabecalho(); //Imprime o cabeçalho da aplicação
				printf("  ========================= CONFIGURAÇÃO DO SVXLINK ========================\n\n");
				printf("   O assistente o ajudará a configurar o seu LINK ou REPETIDOR.\n\n");
				printf("   Verificando a existência de cópia de segurança...\n");
				
				printf("   O arquivo rc.local já foi alterado anteriormente.\n");
				printf("   Deseja restaurar a cópia original do arquivo?\n");
				if(decision2Options()==1)
				{
					printf("   Restaurando a cópia do arquivo original...\n");
					system("sudo cp /etc/rc.local.bkp /etc/rc.local");
					printf("   A cópia não é mais necessária. Removendo...\n");
					system("sudo rm /etc/rc.local.bkp");
					printf("   Concluído!\n");
				};
			};

			if(fileExists("/etc/svxlink/svxlink.conf.bkp")==0)
			{
				imprime_tela_cabecalho(); //Imprime o cabeçalho da aplicação
				printf("  ========================= CONFIGURAÇÃO DO SVXLINK ========================\n\n");
				printf("   O assistente o ajudará a configurar o seu LINK ou REPETIDOR.\n\n");
				printf("   Verificando a existência de cópia de segurança...\n");
				
				printf("   Não foi encontrada nenhuma cópia de segurança de /etc/svxlink/svxlink.conf\n");
				printf("   Criando cópia de segurança do arquivo /etc/svxlink/svxlink.conf\n");
				system("sudo cp /etc/svxlink/svxlink.conf /etc/svxlink/svxlink.conf.bkp");
				printf("   Concluído!\n\n");
				
				printf("   Deseja editar o arquivo manualmente, agora?\n");
				printf("   Se preferir a ajuda do assistente, escolha 0\n");
				if(decision2Options()==1)
				{
					system("sudo nano /etc/svxlink/svxlink.conf");
				};
			};
				
			if(fileExists("/etc/svxlink/svxlink.d/ModuleEchoLink.conf.bkp")==0)
			{
				imprime_tela_cabecalho(); //Imprime o cabeçalho da aplicação
				printf("  ========================= CONFIGURAÇÃO DO SVXLINK ========================\n\n");
				printf("   O assistente o ajudará a configurar o seu LINK ou REPETIDOR.\n\n");
				printf("   Verificando a existência de cópia de segurança...\n");
				
				printf("   Não foi encontrada nenhuma cópia de segurança de /etc/svxlink/svxlink.d/ModuleEchoLink.conf\n");
				printf("   Criando cópia de segurança do arquivo /etc/svxlink/svxlink.d/ModuleEchoLink.conf\n");
				system("sudo cp /etc/svxlink/svxlink.d/ModuleEchoLink.conf /etc/svxlink/svxlink.d/ModuleEchoLink.conf.bkp");
				printf("   Concluído!\n\n");
				
				printf("   Deseja editar o arquivo manualmente, agora?\n");
				printf("   Se preferir a ajuda do assistente, escolha 0\n");
				if(decision2Options()==1)
				{
					system("sudo nano /etc/svxlink/svxlink.d/ModuleEchoLink.conf");
				};
			};
			
			if(fileExists("/etc/rc.local.bkp")==0)
			{
				imprime_tela_cabecalho(); //Imprime o cabeçalho da aplicação
				printf("  ========================= CONFIGURAÇÃO DO SVXLINK ========================\n\n");
				printf("   O assistente o ajudará a configurar o seu LINK ou REPETIDOR.\n\n");
				printf("   Verificando a existência de cópia de segurança...\n");
				
				printf("   Não foi encontrada nenhuma cópia de segurança de /etc/rc.local\n");
				printf("   Criando cópia de segurança do arquivo /etc/rc.local\n");
				system("sudo cp /etc/rc.local /etc/rc.local.bkp");
				printf("   Concluído!\n\n");
				
				printf("   Deseja editar o arquivo manualmente, agora?\n");
				printf("   Se preferir a ajuda do assistente, escolha 0\n");
				if(decision2Options()==1)
				{
					system("sudo nano /etc/rc.local");
				};
			};
			
			if(fileExists("/etc/svxlink/svxlink.conf.bkp")==1)
			{
				if(fileExists("/etc/svxlink/svxlink.d/ModuleEchoLink.conf.bkp")==1)
				{
					if(fileExists("/etc/rc.local.bkp")==1)
					{
						imprime_tela_cabecalho(); //Imprime o cabeçalho da aplicação
						printf("  ========================= CONFIGURAÇÃO DO SVXLINK ========================\n\n");
						printf("   O assistente apresenta melhores resultados se os arquivos ainda não\n   tiverem sido alterados.\n\n   Caso não funcione, escolha a opção 8 no menu principal novamente e\n   restaure as cópias originais dos arquivos.\n");
						sleep(TMP);
						sleep(TMP);
						imprime_tela_cabecalho(); //Imprime o cabeçalho da aplicação
						printf("  ========================= CONFIGURAÇÃO DO SVXLINK ========================\n\n");
						printf("   O assistente o ajudará a configurar o seu LINK ou REPETIDOR.\n\n");
						system("sudo python configuration-assistent.py");
					}
				}
			};
			
			// Ajuste dos níveis de áudio (ALSAMIXER)
			imprime_tela_cabecalho(); //Imprime o cabeçalho da aplicação
			printf("  ========================= CONFIGURAÇÃO DO SVXLINK ========================\n\n");
			printf("   O assistente o ajudará a configurar o ALSAMIXER.\n\n");
			
			printf("   Os áudios de entrada e saída são gerenciados pela ALSAMIXER.\n");
			printf("   É recomendável ajustar os níveis de áudio nos limites mínimos.\n");
			printf("   Ajuste inclusive o volume do seu transceptor.\n\n");
			printf("   Deseja executar o utilitário de configuração do ALSAMIXER agora?\n");
			if(decision2Options()==1)
			{
				printf("   Abrindo alsamixer...\n");
				system("sudo alsamixer");
				printf("   Concluído!\n   Caso apresente resultado indesejado repita a operação.\n");
			};
			
        }

        else if (Opt == 9)
        {
			printf("   Esta opção funciona apenas no modo Desktop(Ambiente Gráfico).\n");
			system("chromium-browser wp.me/p1Srmy-9n");
        }

        else if (Opt == 10)
        {
			printf("   Esta opção funciona apenas no modo Desktop(Ambiente Gráfico).\n");
            system("chromium-browser pu8asr.github.io/svxlink-automake");
        }

        else if (Opt == 11)
        {
			printf("   Esta opção funciona apenas no modo Desktop(Ambiente Gráfico).\n");
			system("chromium-browser conferenciaamazonica.wordpress.com");
        }

        else if (Opt == 0)
        {
           // creditos();
        }

        else if (Opt > 11)
        {
			imprime_tela_cabecalho(); //Imprime o cabeçalho da aplicação
            printf("\n\n                                 Opção Inválida!\n");
        }

    } while (Opt != 0);

    return 0;
}
/* Fim do corpo principal da aplicação */
