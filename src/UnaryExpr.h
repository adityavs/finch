#pragma once

#include <iostream>

#include "Macros.h"
#include "Expr.h"
#include "ExprVisitor.h"
#include "Ref.h"
#include "String.h"

namespace Finch
{
    // AST node for an unary message send: "obj message"
    class UnaryExpr : public Expr
    {
    public:
        UnaryExpr(Ref<Expr> receiver, String message)
        :   mReceiver(receiver),
            mMessage(message)
        {}
        
        Ref<Expr> Receiver() const { return mReceiver; }
        String    Message() const { return mMessage; }
        
        virtual void Trace(std::ostream & stream) const;
        
        EXPRESSION_VISITOR

    private:
        // the object receiving the message
        Ref<Expr> mReceiver;
        
        // the name of the message
        String mMessage;
    };
}