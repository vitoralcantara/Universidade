// -------------------------------------------------------------------
// Pair.java 
// -------------------------------------------------------------------

package lb09.lib ;

/**
 * This   class  represents   an   ordered  pair   of  generic   types
 * <code>X</code> and <code>Y</code>.
 *
 * @author Marcelo Ferreira Siqueira
 * @author <a href="mailto:mfsiqueira@dimap.ufrn.br">mfsiqueira@dimap.ufrn.br</a>
 * @author <a target="_blank" href="http://www.dimap.ufrn.br/~mfsiqueira">www.dimap.ufrn.br/~mfsiqueira</a>
 * @version 1.0,  &nbsp; 2009-MAY-11
 * @since JDK1.5
 *
 */

public class Pair< X , Y >
{
    /**
     * A reference to the first element of the pair.
     *
     */
    private X firstElement ;


    /**
     * A reference to the second element of the pair.
     *
     */
    private Y secondElement ;


    /**
     * Constructor used to instantiate this object.  It is responsible
     * for setting the references for the first and second elements of
     * the pair.
     *
     * @param x  A <code>X</code> object  to be assigned to  the first
     * element of the pair.
     * @param y A  <code>Y</code> object to be assigned  to the second
     * element of the pair.
     */
    public Pair( X x , Y y ) {
	firstElement  = x;
	secondElement = y ;
    }


    /**
     * Returns a  <code>X</code> object representing  first element of
     * the pair.
     *
     * @return A <code>X</code>  object representing the first element
     * of the pair.
     *
     * @see #getSecondElement
     */
    public X getFirstElement()  
    { 
	return firstElement ; 
    }


    /**
     * Returns a <code>Y</code> object representing the second element
     * of the pair.
     *
     * @return A <code>Y</code> object representing the second element
     * of the pair.
     *
     * @see #getFirstElement
     */
    public Y getSecondElement()  
    { 
	return secondElement ; 
    }


    /**
     * Assigns  a <code>X</code> object  to the  first element  of the
     * pair.
     *
     * @param x  A <code>X</code> object  to be assigned to  the first
     * element of the pair.
     *
     * @see #setSecondElement
     */
    public void setFirstElement( X x )  
    {
	firstElement = x ; 
    }


    /**
     * Assigns a  <code>Y</code> object to  the second element  of the
     * pair.
     *
     * @param y  A <code>Y</code> object  to be assigned to  the first
     * element of the pair.
     *
     * @see #setFirstElement
     */
    public void setSecondElement( Y y ) 
    { 
	secondElement = y ; 
    }

}
