// -------------------------------------------------------------------
// List.java 
// -------------------------------------------------------------------

package lb09.lib ;


/**
 * This class implements a generic, simply connected linked list.
 *
 * @author Marcelo Ferreira Siqueira
 * @author <a href="mailto:mfsiqueira@dimap.ufrn.br">mfsiqueira@dimap.ufrn.br</a>
 * @author <a target="_blank" href="http://www.dimap.ufrn.br/~mfsiqueira">www.dimap.ufrn.br/~mfsiqueira</a>
 * @version 1.0,  &nbsp; 2009-MAY-11
 * @since JDK1.5
 *
 */

public class List< K extends Comparable<K> , V >
{
    /**
     * A reference to the head node of this list.
     *
     */
    ListNode< K , V > headNode ;


    /**
     * Constructor  used to  instantiate this  object.  It  creates an
     * object of the class <code>ListNode</code> to represent the head
     * node of this list.
     *
     * @see #headNode
     * @see ListNode
     */
    public List() 
    {
	headNode = new ListNode< K , V >() ;
    }


    /**
     * Returns the data  associated with an element of  the list whose
     * key was  given as an input  parameter. If such  an element does
     * not belong to the list, then the null reference is returned. 
     *
     * @param key A <code>K</code> object representing the element key.
     * @return A <code>V</code> object representing the element value.
     */
    public V getValue( K key )
    {
	// Search the  list for an element  whose key is  equal to the
	// given one.

	// The reference "prev" will point to the last list element if
	// no  element with  the  given  key is  found  by the  method
	// "find", or it  will point to the element  that precedes the
	// element found.

	ListNode< K , V > prev ;

	prev = findPriorElement( key ) ;

	if ( prev.getNext() == null )
	{
	    return null ;
	}
	else
	{
	    return prev.getNext().getValue() ;
	}
    }


    /**
     * Inserts a new element into  this list. If the given element key
     * belongs to  an element  of the list,  the given element  is not
     * inserted,  and  an  exception  is thrown.  Otherwise,  the  new
     * element is inserted at the tail of the list.
     *
     * @param key A <code>K</code> object representing the element key.
     * @param val A <code>V</code> object representing the element value.
     *
     * @throws IllegalListInsertionException if <code>k</code> is the key of a list element.
     *
     * @see IllegalListInsertionException
     */
    public void insert( K key , V val ) throws IllegalListInsertionException
    {
	// Search the  list for an element  whose key is  equal to the
	// given one.

	// The reference "prev" will point to the last list element if
	// no  element with  the  given  key is  found  by the  method
	// "find", or it  will point to the element  that precedes the
	// element found.

	ListNode< K , V > prev ;

	prev = findPriorElement( key ) ;

	// If   such    an   element   is   found    then   throw   an
	// exception. Otherwise, create a  new node with the given key
	// and value, and insert it at the tail of the list.

	if ( prev.getNext() == null )
	{
	    prev.setNext( new ListNode< K , V>( key , val ) ) ;
	}
	else
	{
	    throw new IllegalListInsertionException() ;
	}
    }


    /**
     * Removes an element from the  list. The method receives a key as
     * its sole input  parameter. If the given key  does not belong to
     * any element of the list, an exception is thrown. Otherwise, the
     * element associated with the given key is removed from the list.
     *
     * @param key A <code>K</code> object representing an element key.
     *
     * @throws IllegalListDeletionException if <code>k</code> is not the key of any list element.
     *
     * @see IllegalListDeletionException
     */
    public void remove( K key ) throws IllegalListDeletionException
    {
	// Search the  list for an element  whose key is  equal to the
	// given one.

	// The reference "prev" will point to the last list element if
	// no  element with  the  given  key is  found  by the  method
	// "find", or it  will point to the element  that precedes the
	// element found.

	ListNode< K , V > prev ;

	prev = findPriorElement( key ) ;

	// If  such  an element  has  not  been  found then  throw  an
	// exception. Otherwise, remove the element from the list.

	if ( prev.getNext() == null )
	{
	    throw new IllegalListDeletionException() ;
	}
	else
	{
	    ListNode< K , V > curr =  prev.getNext() ;

	    prev.setNext( curr.getNext() ) ;

	    curr.setNext( null ) ;
	}
    }


    /**
     * Returns true if the list is empty and false otherwise.
     *
     * @return A logic value (true or false).
     */
    public boolean isEmpty()
    { 
	return headNode.getNext() == null ;
    }


    /**
     * Returns the  list node that immediately precedes  the list node
     * that contains a given key. If  the given key does not belong to
     * any node of the list, then the method returns a null reference.
     *
     * @param key A <code>K</code> object representing an element key.
     * @return A  reference to a  list node that  immediately precedes
     * the list node that contains the given key.
     */
    private ListNode< K , V > findPriorElement( K key )
    {
	ListNode< K , V > prev = headNode ;
	ListNode< K , V > curr = headNode.getNext() ;

	boolean found = false ;

	while ( ( curr != null ) && !found )
	{
	    if ( curr.getKey().compareTo( key ) == 0 )
	    {
		found = true ;
	    }
	    else
	    {
		prev = curr ;
		curr = prev.getNext() ;
	    }
	}

	return prev ;
    }
}


/**
 * This class implements a node for a generic, simply connected linked
 * list.
 *
 * @author Marcelo Ferreira Siqueira
 * @author <a href="mailto:mfsiqueira@dimap.ufrn.br">mfsiqueira@dimap.ufrn.br</a>
 * @author <a target="_blank" href="http://www.dimap.ufrn.br/~mfsiqueira">www.dimap.ufrn.br/~mfsiqueira</a>
 * @version 1.0,  &nbsp; 2009-MAY-11
 * @since JDK1.5
 *
 */

class ListNode< K extends Comparable<K> , V >
{
    /**
     * A reference to an  object of the class <code>Pair</code>, which
     * stores the  key and value  of the element associated  with this
     * node.
     */
    private Pair< K , V > element ;


    /**
     * A  reference to the  successor of  this node  in the  list that
     * contains it.
     */
    private ListNode< K , V > nextNode ;


    /**
     * Constructor with no arguments  used to instantiate this object.
     *
     * @see #ListNode( K key , V value )
     */
    public ListNode() 
    {
	element = null ;
	nextNode = null ;
    }


    /**
     * Constructor with two arguments used to instantiate this object.
     *
     * @param key A <code>K</code> object representing a list element key.
     * @param value A <code>V</code> object representing a list element value.
     *
     * @see #ListNode()
     */
    public ListNode( K key , V value ) 
    {
	element = new Pair< K , V >( key , value ) ;
	nextNode = null ;
    }


    /**
     * Returns the key of the element stored in this node.
     *
     * @return  A <code>K</code>  object representing  the key  of the
     * element stored in this node.
     *
     * @see #getValue
     * @see #getNext
     */
    public K getKey() 
    { 
	return element.getFirstElement() ;
    }


    /**
     * Returns the value of the element stored in this node.
     *
     * @return A  <code>V</code> object representing the  value of the
     * element stored in this node.
     *
     * @see #getKey
     * @see #getNext
     */
    public V getValue() 
    { 
	return element.getSecondElement() ;
    }


    /**
     * Returns a reference  to the successor of this  node in the list
     * that contains it.
     *
     * @return   A  <code>ListNode</code>   object   representing  the
     * successor of this node in the list that contains it.
     *
     * @see #getKey
     * @see #getValue
     */
    public ListNode< K , V > getNext() 
    { 
	return nextNode;
    }


    /**
     * Changes the key of the element associated with this node.
     *
     * @param key A <code>K</code> object representing an element key.
     *
     * @see #setValue
     * @see #setNext
     */
    void setKey( K key )
    { 
	element.setFirstElement( key ) ;
    }


    /**
     * Changes the value of the element associated with this node.
     *
     * @param value A <code>V</code> object representing an element value.
     *
     * @see #setKey
     * @see #setNext
     */
    void setValue( V value )
    { 
	element.setSecondElement( value ) ;
    }


    /**
     * Assigns a <code>ListNode</code> object to the <code>next</code>
     * node reference of this node.
     *
     * @param node A <code>ListNode</code> object.
     *
     * @see #setKey
     * @see #setValue
     */
    public void setNext( ListNode< K , V > node ) 
    { 
	nextNode = node ;
    }

}


