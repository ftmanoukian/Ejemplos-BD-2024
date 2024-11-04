from enum import Enum
from random import randint, shuffle

class dia(Enum):
    l = 'lunes'
    m = 'martes'
    x = 'miercoles'
    j = 'jueves'
    v = 'viernes'
    s = 'sabado'
    d = 'domingo'

def day2num(_dia : dia):
    if _dia == dia.l:
        return 0
    elif _dia == dia.m:
        return 1
    elif _dia == dia.x:
        return 2
    elif _dia == dia.j:
        return 3
    elif _dia == dia.v:
        return 4
    elif _dia == dia.s:
        return 5
    elif _dia == dia.d:
        return 6

def newTarea(diaLimite : dia, duracion : int):
    return {'diaLimite' : diaLimite, 'duracion' : duracion}

# cada dia dura 10 horas
horasOcupadas = [3,5,1,4,8,6,2] # horas ocupadas, ordenadas por dia

#para crear una nueva lista de tareas random descomentar la línea de abajo
#tareas2 = [newTarea(diaLimite = [_ for _ in dia][randint(0,len(dia)-1)], duracion = randint(1,4)) for _ in range(25)]

tareas = [
    {'diaLimite': dia.v, 'duracion': 1},
    {'diaLimite': dia.j, 'duracion': 1},
    {'diaLimite': dia.x, 'duracion': 2},
    {'diaLimite': dia.d, 'duracion': 1},
    {'diaLimite': dia.d, 'duracion': 1},
    {'diaLimite': dia.j, 'duracion': 1},
    {'diaLimite': dia.d, 'duracion': 1},
    {'diaLimite': dia.v, 'duracion': 1},
    {'diaLimite': dia.j, 'duracion': 2},
    {'diaLimite': dia.m, 'duracion': 3},
    {'diaLimite': dia.m, 'duracion': 3},
    {'diaLimite': dia.x, 'duracion': 2},
    {'diaLimite': dia.m, 'duracion': 3},
    {'diaLimite': dia.m, 'duracion': 3},
    {'diaLimite': dia.d, 'duracion': 3},
]

tareas = sorted(tareas, key = lambda x : day2num(x['diaLimite']))

for tarea in tareas:
    print(tarea)

recorrido = [_dia for _dia in dia][-2::-1]

tareasOrdenadas = [[] for _ in range(7)]

for n,_dia in enumerate(recorrido):
    print(f'{'='*100}')
    print(f'Dia actual: {_dia.value} - Horas ya ocupadas: {horasOcupadas[5 - n]}')

    horasOcupadasDiaActual = horasOcupadas[5 - n]
    horasOcupadasPorTareas = 0
    while(horasOcupadasDiaActual + horasOcupadasPorTareas < 10) and len(tareas) >= 1:
        tareasOrdenadas[5 - n].append(tareas.pop(-1))
        horasOcupadasDiaActual += tareasOrdenadas[5 - n][-1]['duracion']

    print('Tareas agregadas al dia actual:')
    for tarea in tareasOrdenadas[5 - n]:
        print(tarea)

