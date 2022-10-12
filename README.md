# Activitat 02 Programant el Kernel de Linux (Mòdul 1)

*Instructor*: [Jordi Mateo Fornés](http:jordimateofornes.com)

*Course*: [Grau en Tècniques d'Interacció Digital i de Computació](http://www.grauinteraccioicomputacio.udl.cat/ca/index.html)

*University*: University of Lleida - Campus Igualada - Escola Politècnica Superior

*Estudiants*: Joan Bonell
              Ricard Bosch

## Part teòrica - Booting

### Enunciat

Quina és la funcionalitat del fitxer que es troben a la carpeta /boot/ de Linux?
  • vmlinuz-* 
  • initrd.img 
  • grub
  • config*
 
### Resposta

  • vmlinuz-* 
    - És un arxiu executable enllaçat estàticament i que conté el nucli Linux en un dels formats executables suportats per Linux, com ara ELF, COFF i         
    a.out. L'arxiu vmlinux pot utilitzar-se en una depuració del nucli, per a generar la taula de símbols o altres operacions, però per a usar-lo com a 
    nucli del sistema operatiu ha de ser capaç d'executar-se i iniciar el computador. Per a això s'ha d'agregar un encapçalat d'arrencada múltiple, un 
    sector d'arrencada i rutines d'inicialització.
  
  • initrd.img 
    - Proporciona la capacitat de carregar un disc RAM mitjançant el carregador d'arrencada. Aquest disc RAM es pot muntar com el sistema d'arxius arrel i 
    els programes es poden executar des d'ell. Els arxius initrd normalment es troben en el directori / boot, anomenat / boot / initrd. img-*kversion amb 
    un / initrd. img és un enllaç simbòlic a l'últim initrd instal·lat.
  
  • grub
    - És un carregador d'arrencada que compleix l'Especificació Multiboot. D'aquesta manera pot arrencar de manera uniforme els kernels que compleixen 
    l'Especificació Multiboot.
    Està dissenyat per a complir els següents objectius, llistats per ordre d'importància:
      - Funcions bàsiques han de ser senzilles per als usuaris finals.
      - Àmplia funcionalitat per a fer costat als experts i dissenyadors del kernel.
      - Compatibilitat amb versions anteriors per a arrencar FreeBSD, NetBSD, OpenBSD i Linux. Els nuclis compatibles com DOS, Windows NT i US/2, són 
      arrancables mitjançant una funció de càrrega en cadena.

    Característiques addicionals que suporta:
     - Reconeix múltiples formats executables.
     - Suporta kernels que no compleixen especificació multiboot.
     - Admet comandos de configuració i pot carregar una configuració preestablerta.
     - Proveeix interfície de menú.
     - Té una interfície de línia de comandos flexible.
     - Admet molts sistemes de fitxers (BtrFS, ext2/*ext3/*ext4, FAT12/FAT16/FAT32, exFAT, HFS, HFS+” ISO9660, nilfs2, NTFS, ReiserFS, ZFS, ROMFS, JFS, 
     XFS, ...).
     - Descompressió automàtica.
     - Accés a dades situades en qualsevol dispositiu instal·lat.
     - Independent de la geometria de la unitat.  
     - Detecta tota la RAM instal·lada.
     - Admet adreçament de bloc lògic (LBA).
     - Arrencada de xarxa.
     - Terminals remots per a permetre el control des d'una estació remota.
  
  • config*
    - És un arxiu que expandeix la línia d'ordres del nucli actual per donar suport a dades addicionals de valor clau quan s'arrenca el 
    nucli d'una manera eficient. Això permet als administradors passar un fitxer de configuració de clau estructurada.

Fonts:
  - wikipedia.com
  - compuhoy.com
  - docs.kernel.org
  

## Part teòrica: Lectura de codi 

### Enunciat

Analitza el següent fragment de codi:

SYSCALL_DEFINE1(my_syscall , char *, msg) {
  printk(KERN_INFO "my_syscall:\"%s\"\n", msg);
  return 0; }

  • Explica amb tots els detalls possibles que fa aquest fragment.
  • Documentat i detalla la sintaxi utiltizada.
  • Analitza si aquest fragment pot tenir algun perill en temps d’execució o compilació. En cas afirmatiu indica quin. En cas negatiu, justifica la 
  resposta

### Resposta

SYSCALL_DEFINE1(my_syscall , char *, msg) {
  printk(KERN_INFO "my_syscall:\"%s\"\n", msg);
  return 0; }
  
- La primera linea fa una crida ha sistema i li passa un paràmetre, que és un punter a char.
  SYSCALL_DEFINE1 es una macro que defineix una funció de crida al sistema.

- La segona linea es una funció que imprimeix el missatge que li passem per paràmetre. El missatge que li passem per paràmetre és el que li passem a la funció my_syscall.
  prinkt() és una funció que imprimeix el missatge que li passem per paràmetre.
  KERN_INFO es una constant que defineix el nivell d'informació que es vol imprimir. En aquest cas, és el nivell d'informació més alt.
  
- El perill que té aquest codi en temps d'execució és que no imprimeix res per pantalla. 
  Al no veure el missatge que li passem per paràmetre a la funció my_syscall, no sabrem si la funció my_syscall funciona correctament o no.
- En temps de compilació és no té cap perill en temps de compilació.

## Part teòrica: GetTimes

### Enunciat

Realitzeu la implementació, integració i test d’una nova crida a sistema anomenada gettimes. gettimes(int
pid, struct ptimes *pt). Aquesta crida ens permetrà obtenir informació sobre un procés concret com: 

  • real: temps total del procés.
  • user: quantitat de temps de CPU invertit en mode d’usuari. 
  • sys: quantitat de temps de CPU invertit en mode nucli.

  • Implementeu la crida a sistema.
  • Integreu la crida al vostre kernel.
  • Implementeu un codi amb C per testar-la. Aquest codi és pot dir (test.c).
  
### Resposta




  

