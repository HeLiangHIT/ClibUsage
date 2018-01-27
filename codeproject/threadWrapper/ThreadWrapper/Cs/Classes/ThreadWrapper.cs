/*
	Thread Wrapper v.2.0

	Copyright (C) 2017 by Sergey A Kryukov
	http://www.SAKryukov.org
	http://www.codeproject.com/Members/SAKryukov	

	Original publications:
	https://www.codeproject.com/Articles/1177478/Thread-Wrapper-CPP
	https://www.codeproject.com/Articles/1177869/Conveyor-Thread-Wrapper-CPP
	https://www.codeproject.com/Articles/1170503/The-Impossibly-Fast-Cplusplus-Delegates-Fixed
	https://www.codeproject.com/Tips/149540/Simple-Blocking-Queue-for-Thread-Communication-and
*/

namespace Threading {
    using System;
    using Thread = System.Threading.Thread;
    using ManualResetEvent = System.Threading.ManualResetEvent;

    abstract class ThreadWrapper {

        internal ThreadWrapper() {
            Thread = new Thread(Body);
        } //ThreadWrapper

        internal void Start(bool letGo) {
            Thread.Start();
            if (!letGo) return;
            WakeUp();
        } //Start
        internal void Abort() {
            Thread.Abort();
        } //Abort
        internal void PutToSleep() {
            SleepEvent.Reset();
        } //PutToSleep
        internal void WakeUp() {
            SleepEvent.Set();
        } //WakeUp

        internal event EventHandler Paused;

        protected abstract void Body(); 
        
        protected void SyncPoint() {
            SleepEvent.WaitOne();
        } //SyncPoint

        private ManualResetEvent SleepEvent = new ManualResetEvent(false);

        Thread Thread;

    } //class ThreadWrapper

} //namespace Threading
