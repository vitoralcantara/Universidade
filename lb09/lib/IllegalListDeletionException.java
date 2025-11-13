// -------------------------------------------------------------------
// IllegalListDeletionException.java 
// -------------------------------------------------------------------

package lb09.lib ;


/**
 * This  class  represents  an   exception  trigged  by  the  deletion
 * operation of the class <code>List</code>.
 *
 * @author Marcelo Ferreira Siqueira
 * @author <a href="mailto:mfsiqueira@dimap.ufrn.br">mfsiqueira@dimap.ufrn.br</a>
 * @author <a target="_blank" href="http://www.dimap.ufrn.br/~mfsiqueira">www.dimap.ufrn.br/~mfsiqueira</a>
 * @version 1.0,  &nbsp; 2009-MAY-11
 * @since JDK1.5
 *
 * @see lb10.src.List
 */

public class IllegalListDeletionException extends Exception 
{
    /**
     * Constructor  used to  instantiate this  object.
     *
     */
    public IllegalListDeletionException()
    {
	// Invokes the superclass constructor.
	super( "The given key does not belong to any element of this list" );
    }

}
