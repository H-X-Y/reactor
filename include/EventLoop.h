#pragma once

#include"Thread.h"

namespace reactor{
    class EventLoop{
        public:
            EventLoop(EventLoop&) = delete;
            EventLoop& operator=(const EventLoop&) = delete;
            EventLoop();
            ~EventLoop();

            void loop();

            void assertInLoopThread(){
                if(!isInLoopThread()){
                    abortNotInLoopThread();
                }
            }

            bool isInLoopThread() const {return threadId_ == muduo::CurrentThread::tid();}
        
        private:
            void abortNotInLoopThread();

            bool looping_;
            const int threadId_;
    };
}