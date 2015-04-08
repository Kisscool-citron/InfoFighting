#ifndef ISTATE_H
#define ISTATE_H


class IState
{
     //charge et crée les élements du state
    virtual void Init()=0;

    //process tous ce qu'il faut dans la state
    virtual EState Process()=0;

    //nettoie tous les élements créés
    virtual void Clean()=0;

};

#endif // ISTATE_H
