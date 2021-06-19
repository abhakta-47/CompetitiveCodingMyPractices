from math import floor
import multiprocessing

def bar_update():
    print("***")
    print(completed.qsize())
    print(" outof "+str(sqrtotal))


def chekr(x,y,completed):
    # print(str(x)+","+str(y))
    if(7*x+5*y>total or 11*x+2*y>total):
        return
    if( (7*x+5*y)%(11*x+2*y)==0 ):
        print(str(7*x+5*y)+"%"+str(11*x+2*y)+" "+str((7*x+5*y)%(11*x+2*y)))
        # ++ans;
    completed.put(1);
    bar_update()

if __name__ == '__main__':
    total=12345678910
    sqrtotal=total*total    
    print(total)
    ans=0
    

    processes=[]
    completed=multiprocessing.Queue()
    for x in range(1,floor(total/7)):
        for y in range(1,floor(total/5)):
            p=multiprocessing.Process(
                target=chekr, 
                args=(x,y,completed,)
            )
            processes.append(p)
            p.start()
    for process in processes:
        process.join()