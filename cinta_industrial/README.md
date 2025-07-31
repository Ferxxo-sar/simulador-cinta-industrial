💡 Simulador de Cinta Transportadora Industrial en C | Proyecto de Automatización


Proyecto en lenguaje C para control de una cinta transportadora con detección de piezas defectuosas y persistencia de datos.

🚀 Objetivo del proyecto

Este proyecto simula una cinta transportadora industrial controlada por un sistema embebido simple. 
Está pensado como una introducción realista a la automatización industrial, con enfoque en la lógica de control, detección de fallas, estados del sistema y persistencia de datos.
Es objetivo es desarrollar y mejorar mis habilidades técnicas en programación en C aplicada a entornos industriales.

🎓 Tecnologías y herramientas utilizadas

Lenguaje C (100%)

Windows (consola y Sleep, conio.h)

Git / GitHub para control de versiones

Persistencia con archivos de texto (fopen, fprintf, localtime) 
Se crea un archivo de texto cuyo titulo es la fecha del dia en que registran todas las fallas que se presentaron en la cinta.

Simulación de fallas generada de manera aleatoria con rand()


👨‍🌾 Aplicación en el ámbito industrial

Este simulador reproduce condiciones de una línea de producción real, como podrían encontrarse en industrias automotrices, de alimentos o textiles:

Control de procesos en tiempo real

Gestión de paradas por mantenimiento o emergencia

Registro y trazabilidad de errores

Bases para integración con sensores y actuadores reales


🔧 Compilación y ejecución

Requisitos: 
- Sistema operativo Windows
- Compilador compatible con ANSI C (recomendado: MinGW, TDM-GCC)


📅 Ejemplo de salida (simulada)

Sistema encendido: Si
Sistema pausa: No
Sistema emergencia: No
Piezas procesadas: 84
Piezas defectuosas: 8
Pieza 85: [DEFECTUOSA] - 16:02:03

El archivo generado se guarda como:

registro_2025-07-31.txt

🌟 Autor

Fernando Sarquis, estudiante de la UTN con gran motivación por ingresar al mundo de la automatización industrial.
Me encanta programar en C y por eso quiero profesionalizarme en sistemas embebidos y entornos industriales.

"Este proyecto fue creado desde cero, sin uso de ia, para aprender lógica industrial, control por estados y buenas prácticas de programación en C orientadas a la industria."

📊 Próximas mejoras (roadmap)

Generar un codigo de defecto para cada pieza defectuosa.
Paginar los modulos estilo SCADA/PLC.
Cuando se detectan fallas consecutivas entrar en modo de emergencia automaticamente.



🌐 Licencia

Este proyecto es libre para uso personal, educativo y profesional. Se valora el reconocimiento del autor si se utiliza como base.

🔗 LinkedIn https://www.linkedin.com/in/sarquisfer/ 🌐 GitHub https://github.com/Ferxxo-sar
